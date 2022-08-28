package main

import "fmt"

func main(){
	var i int = 5
	//二进制输出
	fmt.Printf("%b\n",i)
	
	//八进制
	var j int = 011
	fmt.Println("j=",j)

	//十六进制
	var num int = 0x11
	fmt.Println("num=",num)
}