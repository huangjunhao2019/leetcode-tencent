package main

import (
	"bufio"
	"fmt"
	"io"
	"net"
	"os"
)

func sendFile(conn net.Conn, filePath string) {
	file, err := os.Open(filePath)
	if err != nil {
		fmt.Printf("os.Open() err=%v\n", err)
		return
	}
	defer file.Close()
	buf := make([]byte, 4096)
	for {
		n, err := file.Read(buf)
		if err != nil {
			if err == io.EOF {
				fmt.Println("File sending end")
			} else {
				fmt.Println("file.Read() err=", err)
			}
			break
		}
		_, err = conn.Write(buf[:n])
	}
	conn.Write([]byte("endFile"))
}
func getAllFileName(filePathSlice []string, path string) (res []string) {
	file, err := os.Open(path)
	if err != nil {
		fmt.Println("os Open mom file err=", err)
		return
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	for {
		str, err := reader.ReadString('\n')
		if err == io.EOF {
			break
		}
		filePathSlice = append(filePathSlice, str[0:len(str)-1])
	}
	//fmt.Println(filePathSlice)
	res = filePathSlice
	return
}

// func main() {
// 	filePath := make([]string, 0)
// 	filePath = getAllFileName(filePath, "./filePath")
// 	fmt.Println(len(filePath))
// 	for _, file := range filePath {
// 		fmt.Println(file)
// 	}
// }

func main() {
	command := os.Args
	if len(command) != 3 {
		fmt.Println("Command argument error")
		return
	}
	ipAdr := command[1]
	path := command[2]
	_, err := os.Stat(path)
	if err != nil {
		fmt.Printf("os.Stat() err=%v\n", err)
		return
	}
	fmt.Println(ipAdr)
	conn, err := net.Dial("tcp", ipAdr)
	if err != nil {
		fmt.Println("net.Dial() err=", err)
		return
	}
	defer conn.Close()
	filePathSlice := make([]string, 0)
	filePathSlice = getAllFileName(filePathSlice, path) //把文件内容读出来，将存储文件路径写入到slice中
	fmt.Println(filePathSlice)
	for _, filePath := range filePathSlice {
		//fmt.Println(filePath)
	
		fileInfo, err := os.Stat(filePath)
		if err != nil {
			fmt.Printf("%v has err=%v",fileInfo.Name(), err)
			continue
		}
		//fmt.Println(fileInfo.Name())
		_, err = conn.Write([]byte(fileInfo.Name()))
		buf := make([]byte, 4096)
		n, err := conn.Read(buf)
		if err != nil {
			fmt.Printf("conn.Read() err=%v\n", err)
			return
		}
		if string(buf[:n]) == "ok" {
			sendFile(conn, filePath)
		}
	}
	// _, err = conn.Write([]byte(fileInfo.Name()))
	// buf := make([]byte, 4096)
	// n, err := conn.Read(buf)
	// if err != nil {
	// 	fmt.Printf("conn.Read() err=%v\n", err)
	// 	return
	// }
	// if string(buf[:n]) == "ok" {
	// 	sendFile(conn, path)
	// }
}
