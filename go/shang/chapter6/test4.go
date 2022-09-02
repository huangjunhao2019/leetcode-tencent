package main

import "fmt"
func test1(n int){
	if n>2{
		n--
		test1(n)
	}
	fmt.Println(n)
}
func test2(n int){
	if n>2{
		n--
		test2(n)
	} else {
		fmt.Println(n)
	}
}
func main(){
	fmt.Println("test1")
	test1(4)

	fmt.Println("test2")
	test2(4)
}