package main

import "fmt"
type Monster struct{
	Name string
	Age int
}
func main(){
	var monster1 Monster
	monster1.Name = "牛魔王"
	monster1.Age = 500

	monster2 := monster1
	fmt.Printf("monster1=%v, monster1的地址=%p\n",monster1,&monster1)
	fmt.Printf("monster2=%v, monster2的地址=%p\n",monster2,&monster2)
}