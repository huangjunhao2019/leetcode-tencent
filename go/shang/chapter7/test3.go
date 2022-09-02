package main

import "fmt"

func main(){
	//数组创建后，如果没有赋值，默认为零值
	//1. 数值 --> 0
	//2. 字符串 --> ""
	// 3. bool --> false

	var arr1 [3]float32
	var arr2 [3]string
	var arr3 [3]bool
	fmt.Printf("arr1=%v\narr2=%v\narr3=%v\n",arr1,arr2,arr3)
}