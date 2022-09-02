package main

import "fmt"

func getSumAndSub(n1 int,n2 int)(int,int){
	sum := n1+n2
	sub := n1-n2
	return sum,sub
}
func main(){
	n1 := 10
	n2 := 20
	sum,sub := getSumAndSub(n1,n2)
	fmt.Println("sum= ",sum,"sub= ",sub)
	_,res3 := getSumAndSub(n1,n2)
	fmt.Println("res3= ",res3)
}