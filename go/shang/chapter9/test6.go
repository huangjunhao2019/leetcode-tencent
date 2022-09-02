package main

import "fmt"
type Stu struct {
	Name string
	Age int
	Address string
}
func main(){
	students := make(map[string]Stu)
	stu1 := Stu{"tom",10,"北京"}
	stu2 := Stu{"mary",28,"上海"}
	students["no1"]=stu1
	students["no2"]=stu2
	fmt.Println(students)

	//遍历各个学生的信息
	for k,v := range students{
		fmt.Printf("学生的编号是%v\n",k)
		fmt.Printf("学生的名字是%v\n",v.Name)
		fmt.Printf("学生的年龄是%v\n",v.Age)
		fmt.Printf("学生的地址是%v\n",v.Address)
		fmt.Println()
	}
}