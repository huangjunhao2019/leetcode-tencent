package main

import "fmt"

//变量使用的注意事项
func main(){
	var i int = 10
	i = 30
	i = 50
	fmt.Println("i=",i)
	// i = 1.2 //报错，不能改变数据类型
	var i int =50 //重复定义
	i := 100 //重复定义

}