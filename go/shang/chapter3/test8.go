package main

import (
	"fmt"
	"unsafe"
)

//演示golang中字符类型使用
func main(){
	var c1 byte = 'a'
	var c2 byte = 'c'
	//当直接输出byte值，就是输出了字符对应的码值
	fmt.Println("c1=",c1)
	fmt.Println("c2=",c2)
	//如果希望输出对应字符，需要使用格式化输出
	fmt.Printf("c1=%c c2=%c\n",c1,c2)

 	// var c3 byte = '北'
 	// fmt.Printf("c3=%c\n",c3)
	var c4 int = '北'
	fmt.Printf("c4=%c c4对应的码值%d\n",c4,c4)
	fmt.Println(unsafe.Sizeof(c4),unsafe.Sizeof(c1))

	var c5 int = 120
	fmt.Printf("%c\n",c5)
	var n1 = 10 + 'a'
	fmt.Printf("n1=%d\n",n1)
 }