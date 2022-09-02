package main

import "fmt"
var name = "tom"
func test1(){
	fmt.Println(name)
}
func test2(){
	name := "jack"
	fmt.Println(name)
}
func main(){
	fmt.Println(name)
	test1()
	test2()
	test1()
}