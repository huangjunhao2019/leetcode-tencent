package main

import "fmt"
type A struct{
	Name string
	Age int
}
type Stu struct{
	A 
	int //没有指端，直接通过stu.int来访问
}
func main(){
	stu := Stu{}
	stu.Name="tom"
	stu.Age=10
	stu.int=80
	fmt.Println(stu)
}