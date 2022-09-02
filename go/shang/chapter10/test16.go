package main

import "fmt"
type Person struct{
	Name string
}
func (p Person)test03(){
	p.Name="jack"
	fmt.Println("test03()=",p.Name)
}
func main(){
	p := Person{"tom"}
	(&p).test03()
	fmt.Println("p.Name=",p.Name)
}