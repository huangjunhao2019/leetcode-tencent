package main

import "fmt"

type A struct{
	Name string
	age int
}
func (a *A) sayOk(){
	fmt.Println("A sayOk",a.Name)
}
func (a *A) hello(){
	fmt.Println("A hello",a.Name)
}
type B struct{
	A
	Name string
}
func (b *B) sayOk(){
	fmt.Println("B sayOk",b.Name)
}
func main(){
	var b B
	b.Name="JACK"
	b.A.Name="Mary"
	b.age=100
	b.sayOk()
	b.hello()
}