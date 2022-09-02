package main

import "fmt"

func main(){
	//演示切片的基本使用
	var intArr [5]int=[...]int{1,22,33,66,99}
	//声明/定义一个切片
	//1. slice就是切片的名称
	//2. intArr[1:3]表示slice引用到intArr这个数组的下标为1的元素到下标为2的元素
	//3. 引用intArr数组的起始下标为1，最后的下标为3，但是不包含3
	slice := intArr[1:3] 
	fmt.Println("intArr=",intArr)
	fmt.Println("silce的元素是 =",slice)
	fmt.Println("slice的元素个数=",len(slice))
	fmt.Println("slice的容量=",cap(slice))
	fmt.Printf("slice的地址=%v\n",&slice[0])
	fmt.Printf("intArr[1]的地址=%v\n",&intArr[1])
}