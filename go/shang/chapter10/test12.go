package main

import "fmt"
type Student struct{
	Name string
	Age int
}
func (stu *Student)String() string {
	str := fmt.Sprintf("Name=[%v], Age=[%v]",stu.Name,stu.Age)
	return str
}
func main(){
	stu := Student{
		Name : "tom",
		Age : 20,
	}
	fmt.Println(stu) //不调用String
	fmt.Println(&stu) //调用了自定义的Stirng
}