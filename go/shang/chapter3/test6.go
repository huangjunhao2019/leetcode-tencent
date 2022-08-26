package main

import (
	"fmt"
	"unsafe"
)

//演示Golang中整数类型的使用
func main(){
	var n1 = 100
	// 查看变量的数据类型
	//fmt.Printf()
	fmt.Printf("n1 的类型 %T\n",n1)

	//查看变量的占用字节大小
	var n2 int32 = 10
	fmt.Printf("n2 的类型 %T, n2 占用的字节数是 %d \n",n2,unsafe.Sizeof(n2))
}