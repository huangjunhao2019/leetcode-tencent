package main

import "fmt"

type Student struct{
	Name string
	Age int
}
type Stu Student

func main(){
	var stu1 Student
	var stu2 Stu
	stu2 = stu1 //错误，但是改成stu2=Stu(stu1)就对了
	fmt.Println(stu1,stu2)
}