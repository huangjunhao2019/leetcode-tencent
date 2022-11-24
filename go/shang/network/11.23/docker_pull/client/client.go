package main

import (
	"bufio"
	"fmt"
	"io"
	"net"
	"os"
)

func getFile(conn net.Conn, fileName string, path string) (string, error) {
	resPath := path + fileName
	f, createErr := os.Create(resPath)
	if createErr != nil {
		return resPath, createErr
	}
	fmt.Println("getFile buf=",fileName)
	buf := make([]byte, 1024)
	for {
		n, readErr := conn.Read(buf)
		//fmt.Println("getFile buf=", string(buf[:n]))
		if readErr != nil {
			if readErr == io.EOF {
				//fmt.Println("readErr",readErr)
				break
			}
			return resPath, readErr
		}
		_, writeErr := f.Write(buf[:n])
		if writeErr != nil {
			return resPath, writeErr
		}
		 
	}
	return resPath, nil
}
func pullLayer(netAddr string, layerName string) {
	conn,err := net.Dial("tcp",netAddr)
	defer conn.Close()
	if err!=nil{
		fmt.Println("pullLayer err=",err)
		return 
	}
	_, writeErr := conn.Write([]byte("layer:" + layerName))
	if writeErr != nil {
		fmt.Println("writeErr2=", writeErr)
		return
	}
	getFile(conn, layerName, "./layer/")
}
func pull(threadChan chan int, image string, netAddr string) {
	conn, dialErr := net.Dial("tcp", netAddr)
	//defer conn.Close()
	if dialErr != nil {
		fmt.Println("dialErr=", dialErr)
		return
	}
	_, writeErr := conn.Write([]byte("image:" + image)) //第一个信息：image名字,服务器需要返回一个文件
	if writeErr != nil {
		fmt.Println("writeErr1=", writeErr)
		return
	}
	manifest, errGetMani := getFile(conn, image, "./mani/") //其中miniest是文件路径名
	if errGetMani != nil {
		fmt.Println("errGetMani=", errGetMani)
		return
	}
	fmt.Println("manifest", manifest)
	conn.Close()
	file, errOpen := os.Open(manifest)
	if errOpen != nil {
		fmt.Println("errOpen=", errOpen)
		return
	}
	defer file.Close()
	reader := bufio.NewReader(file) 
	for{
		layerByteSlice, _, errReadString := reader.ReadLine()
		layerName := string(layerByteSlice)
		fmt.Println("layerName=", layerName)
		if errReadString != nil {
			if errReadString == io.EOF {
				fmt.Println( "manifest文件读取完毕") 
				break
			} else {
				fmt.Println("errReadString=", errReadString)
				break
			} 
		} else {
			threadChan <- 0 //三个线程限制，如果到了三个线程，会阻塞
			go pullLayer(netAddr, layerName)
			<-threadChan
		}
	}
	for len(threadChan)!=0{

	}
}
func main() {
	//1. 输入要拉取的image名称
	//2. 向server端发起要求，要求获得相应的image文件
	//3. 根据获取的image文件，对其内容进行遍历，启动三个协程，进行拉取
	var image string
	threadChan := make(chan int, 3)
	defer close(threadChan)
	netAddr := "127.0.0.1:8080"
	for {
		fmt.Println("输入拉取的镜像名//输入\"end\"结束")
		fmt.Scanln(&image)
		if image == "end" {
			break
		}
		go pull(threadChan, image, netAddr)
		fmt.Println("pull has finished")
	}
	fmt.Println("程序结束")
}
