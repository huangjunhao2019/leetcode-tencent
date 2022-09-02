package main

import "fmt"

func sum(n1 int,args... int) int {
	res := n1
	//遍历args
	for i := 0;i<len(args);i++{
		res += args[i]
	}
	return res
}
func main(){
	fmt.Println("hello")
}