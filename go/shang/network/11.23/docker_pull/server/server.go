package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

func sendFile(fileName string, conn net.Conn, path string) {
	//layer形式：layer:layename

	f, err := os.Open(path + fileName)
	if err != nil {
		fmt.Println("os.Open err=", err)
		return
	}
	defer f.Close()

	//读文件内容，读多少，发送多少
	buf := make([]byte, 1024)
	for {
		n, err := f.Read(buf)
		if err != nil {
			if err == io.EOF {
				//conn.Write([]byte("file:end")) //用以标识文件发送完毕
				fmt.Println("文件发送完毕")
			} else {
				fmt.Println("f.Read err=", err)
			}
			return
		}
		//发送内容
		n, err_conn := conn.Write(buf[:n]) //给服务器发送内容
		if err_conn != nil {
			fmt.Println("err_conn=", err_conn)
		}

	}
}
func solve(conn net.Conn) {
	defer conn.Close()
	buf := make([]byte, 1024)
	n, connErr := conn.Read(buf)
	fmt.Println(string(buf[:n]))
	if connErr != nil {
		fmt.Println("connErr=", connErr)
		return
	}
	image := string(buf[:n])
	if len(image) > 6 && image[:6] == "image:" {
		fmt.Println("image=",image[6:])
		sendFile(image[6:], conn, "./manifest/")
	}  else if len(image)>6 && image[:6]=="layer:"{
		fmt.Println("layer=",image[6:])
		sendFile(image[6:],conn,"./layer/")
	} else{
		return 
	}
	// for {
	// 	n, layerReadErr := conn.Read(buf)
	// 	if layerReadErr != nil {
	// 		if layerReadErr == io.EOF {
	// 			fmt.Printf("%v has been sended\n", image)
	// 		} else {
	// 			fmt.Println("layerReadErr=", layerReadErr)
	// 		}
	// 		return
	// 	}
	// 	layerName := string(buf[:n])
	// 	go sendFile(layerName[6:], conn, "./layer/")
	// }
}
func main() {
	netAddr := "127.0.0.1:8080"
	listener, listenErr := net.Listen("tcp", netAddr)
	defer listener.Close()
	if listenErr != nil {
		fmt.Println("listenErr=", listenErr)
		return
	}
	for {
		conn, acceptErr := listener.Accept()
		if acceptErr != nil {
			fmt.Println("acceptErr=", acceptErr)
			return
		}
		fmt.Println(conn.RemoteAddr().String())
		go solve(conn)
	}
}
