package main

import "fmt"
var age int = test()
//为了看到全局变量是先被初始化的，写出一个函数
func test() int{
	fmt.Println("test()")
	return 90
}
func init(){

	fmt.Println("init()...")
}
func main(){
	fmt.Println("main()...")
}