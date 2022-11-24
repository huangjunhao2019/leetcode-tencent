package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	//主动连接服务器
	conn, err := net.Dial("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("net.Dial err=", err)
		return
	}
	//main调用完毕，关闭连接
	defer conn.Close()

	//接收服务器回复数据

	go func() {
		//切片缓存
		buf := make([]byte, 1024)
		for {
			n, err := conn.Read(buf)
			if err != nil {
				fmt.Println("conn.Read err=", err)
				return
			}
			fmt.Println(string(buf[:n])) //打印接收到的内容
		}
	}()
	//从键盘输入内容，给服务器发送内容

	str := make([]byte, 1024)
	for {
		n, err := os.Stdin.Read(str) //从键盘读取内容
		if err != nil {
			fmt.Println("os.Stdin err=", err)
			return
		}
		//把输入的内容给服务器发送
		conn.Write(str[:n])
		if string(str[0:n-1]) == "exit" {
			return
		}

	}
}
