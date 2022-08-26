package main

import "fmt"

func main(){
	// : 不能省略，否则错误
	name := "tom"
	// 等价于 var name string = "tom"
	fmt.Println("name=",name)
}