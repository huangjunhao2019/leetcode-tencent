package main

import(
	"fmt"
	"net"
	"bufio"
	"os"
	"strings"
)

func main(){
	conn,err := net.Dial("tcp","127.0.0.1:8888")
	if err != nil{
		fmt.Println("dlient dial err=",err)
		return 
	}
	//1.客户端可以发送单行数据，然后就退出
	for{
		reader := bufio.NewReader(os.Stdin) //标准输入

		//从终端读取一行用户输入，并准备发送到服务器
		line,err := reader.ReadString('\n')
		if err!=nil{
			fmt.Println("readString err=",err)
		}
		//如果用户输入的是exit就退出
		line=strings.Trim(line," \r\n")
		if line=="exit"{
			fmt.Println("客户端退出")
			break
		}
		
		//再将line发送给服务器
		_,err2 := conn.Write([]byte(line+"\n"))
		if err2!=nil{
			fmt.Println("conn.Write err=",err2)
			return 
		}
		//fmt.Printf("客户端发送了%d字节的数据 ",n)
	}
}