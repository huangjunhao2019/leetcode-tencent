package main

import "fmt"

func main(){
	var age int
	fmt.Scanln(&age)
	if age>=18{
		fmt.Println("你已经年满18岁，需要对自己行为负责")
	} else {
		fmt.Println("你的年龄不大，放过你了")
	}
}