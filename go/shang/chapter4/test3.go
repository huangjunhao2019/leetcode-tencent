package main

import "fmt"

func main(){
	//在golang中，++ 和 -- 只能独立使用
	var i int = 8
	var a int
	a = i++ //错误，不能用于赋值
	a = i-- //错误，不能用于赋值
	if i++ >0 { //错误，只能当做一个独立的语句，不能参与比较
		fmt.Println("Ok")
	}
}