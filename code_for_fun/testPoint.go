package main

import "fmt"

type Student struct{
	name string
	age *int
}
func main(){
	a := 10
	stu1 := &Student{"tom",&a}
	fmt.Println(stu1.age)
	fmt.Println(*stu1.age)
}