package main

import (
	"fmt"
	"net"
)

func main(){
	//监听
	listener,err := net.Listen("tcp","localhost:8080")
	if err!=nil{
		fmt.Println("err=",err)
		return 
	}
	defer listener.Close() //关闭连接，挂电话
	//阻塞，等待用户链接 
	conn,err := listener.Accept()
	if err!=nil{
		fmt.Println("err=",err)
		return 
	}
	//接收用户请求
	buf := make([]byte,1024) //1024
	n,err := conn.Read(buf)
	if err!=nil{
		fmt.Println("err=",err)
		return 
	}
	fmt.Println("buf=",string(buf[:n]))
	conn.Close()
	
	
}