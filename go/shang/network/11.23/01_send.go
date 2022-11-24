package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

// 发送文件内容
func sendFile(path string, conn net.Conn) {
	//以只读方式打开文件
	f, err := os.Open(path)
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
func main() {
	//提示输入文件名
	fmt.Println("请输入需要传输的文件")
	var path string
	fmt.Scan(&path)

	info, err := os.Stat(path)
	if err != nil {
		fmt.Println("os.Stat err=", err)
		return
	}

	//主动连接服务器
	conn, err := net.Dial("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("net.Dial err=", err)
		return
	}
	defer conn.Close()

	//给接收方发送文件名
	_, err2 := conn.Write([]byte(info.Name()))
	if err2 != nil {
		fmt.Println("conn Write err=", err2)
		return
	}
	//接收对方回复，如果回复“ok"，说明对方准备好，可以发文件
	var n int
	buf := make([]byte, 1024)

	n, err = conn.Read(buf)
	if err != nil {
		fmt.Println("conn.Read err=", err)
		return
	}

	if "ok" == string(buf[:n]) {
		//发送文件内容
		sendFile(path, conn)
	}
}
