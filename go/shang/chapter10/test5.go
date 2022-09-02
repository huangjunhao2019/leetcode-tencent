package main

import "fmt"
type A struct{
	Num int
}
type B struct{
	Num2 int
}
func main(){
	var a A
	var b B
	b=B(a)
	fmt.Println("b=",b)
}