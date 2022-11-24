package main

import (
	"fmt"
	"io"
	"net"
	"os"
)

func recvFile(conn net.Conn,fileName string){
	file,err := os.Create("./output/"+fileName)
	if err != nil{
		fmt.Printf("os.Create() err=%v\n",err)
		return 
	}
	defer file.Close()
	for{
		buf := make([]byte,4096)
		n,err := conn.Read(buf)
		if(string(buf[0:n])=="endFile"){
			return 
		}
		file.Write(buf[:n])
		if err!= nil{
			if err == io.EOF{
				fmt.Printf("文件接收完成\n")
			} else{
				fmt.Printf("conn.Read()方法执行错误, err=%v",err)
			}
			return 
		}
	}
}

func main(){
	listener,err := net.Listen("tcp","0.0.0.0:8080")
	if err != nil{
		fmt.Printf("net.Listen() 函数执行错误，错误为: %v\n",err)
		return 
	}
	defer listener.Close()

	conn,err := listener.Accept()
	if err != nil{
		fmt.Printf("listener.Accept() err=%v",err)
		return 
	}
	
	defer conn.Close() 
	for{
		buf := make([]byte,4096)
		n,err := conn.Read(buf)
		if err != nil{
			fmt.Printf("conn.Read() err=%v\n",err)
			return 
		}
		fileName := string(buf[:n])
		conn.Write([]byte("ok"))
		recvFile(conn,fileName)
	}
}