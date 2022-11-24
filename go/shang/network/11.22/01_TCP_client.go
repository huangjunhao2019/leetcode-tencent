package main

import(
	"fmt"
	"net"
)

func main(){
	//等待对面接电话
	conn,err := net.Dial("tcp","127.0.0.1:8080")
	defer conn.Close()
	if err!=nil{
		fmt.Println("err=",err)
		return 
	}
	//写入内容
	var content string
	fmt.Scanf("%s",&content)
	conn.Write([]byte(content)) 
}