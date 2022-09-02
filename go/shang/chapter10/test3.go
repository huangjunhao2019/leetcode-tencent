package main

import "fmt"
type Person struct{
	Name string
	Age int
	Address string
}
func main(){
	var p1 Person
	p1.Age= 10
	p1.Name="小明"
	fmt.Printf("&p1.Name=%p, &p1.Age=%p\n",&p1.Name,&p1.Age)
}