package main

import (
	"fmt"
	"net"
	"strings"
)

func HandleConn(conn net.Conn){
	//获取客户端的网络地址信息
	//函数调用完毕，自动关闭conn
	defer conn.Close()
	addr := conn.RemoteAddr().String()
	fmt.Println("addr connect sucessfule",addr)

	//读取用户数据
	for{
		buf := make([]byte,2014)
		n,err := conn.Read(buf)
		if err!=nil{
			fmt.Println("err=",err)
			return 
		}
		fmt.Printf("[%s]: %s\n",addr,string(buf[:n-1])) //自己写的程序也需要n-1
		if string(buf[:n-1])=="exit"{
			fmt.Println(addr,"exit")
			return 
		}
		conn.Write([]byte(strings.ToUpper(string(buf[:n-1]))))
	}
}
func main(){
	//监听
	listener,err := net.Listen("tcp","127.0.0.1:8080")

	if err!=nil{
		fmt.Println("err=",err)
		return 
	}
	defer listener.Close()

	//连接多个用户
	for{
		conn,err := listener.Accept()
		if err!=nil{
			fmt.Println("err=",err)
			continue
		}
		//处理用户请求，新建一个协程
		go HandleConn(conn)

	}
}