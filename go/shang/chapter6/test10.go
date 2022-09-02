package main

import "fmt"

var(
	fun1 = func(n1 int,n2 int) int{
		return n1*n2
	}
)
func main(){
	//全局匿名函数的使用
	res := fun1(10,20)
	fmt.Println("res=",res)
}