package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

func RecvFile(fileName string, conn net.Conn) {
	//新建文件
	f, err := os.Create(fileName)
	if err != nil {
		fmt.Println("os.Create err=", err)
		return
	}
	buf := make([]byte, 1024)
	var n int
	for {
		n, err = conn.Read(buf) //接收对方发过来的文件内容
		if err != nil {
			if err == io.EOF {
				fmt.Println("文件接收完毕")
			} else {
				fmt.Println("conn.Read err=", err)
			}
			return
		}

		f.Write(buf[:n]) //往文件写入内容
	}

}
func main() {
	//监听
	listener, err := net.Listen("tcp", "127.0.0.1:8080")

	if err != nil {
		fmt.Println("net.Listen err = ", err)
		return
	}
	defer listener.Close()

	//阻塞等待用户连接
	conn, err1 := listener.Accept()
	if err1 != nil {
		fmt.Println("listener.Accept err = ", err)
		return
	}

	buf := make([]byte, 1024)
	var n int
	n, err2 := conn.Read(buf)
	if err2 != nil {
		fmt.Println("conn.Read err", err2)
		return
	}
	fileName := string(buf[:n])
	//读取对方发送的文件名，回复ok
	conn.Write([]byte("ok"))

	//接收文件内容
	RecvFile(fileName, conn)

}
