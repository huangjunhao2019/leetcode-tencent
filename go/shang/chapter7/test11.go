package main

import "fmt"

func main(){ 
	var slice []int = []int{100,200,300}
	fmt.Println("slice=",slice)
	//通过append直接给slice追加具体的元素
	slice = append(slice,400)
	slice = append(slice,500,600)
	fmt.Println("slice= ",slice)
	slice2 := append(slice,700)
	fmt.Println("slice2=",slice2)

	//把切片追加到切片
	slice3 := append(slice,slice...)//后面必须是切片，不能是数组，后面必须有3个点
	fmt.Println("slice3=",slice3)
}