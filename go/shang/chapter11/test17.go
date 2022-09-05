package main

import "fmt"

func main(){
	var x interface{}
	var b float32 = 1.1
	x = b
	//带检测的类型断言
	y,ok := x.(float64) 
	if ok==true{
		fmt.Println("convert ok")
		fmt.Printf("y 的类型%T，值是%v\n",y,y)
	} else{
		fmt.Println("convert fail")
	}
	fmt.Println("继续执行...")
}