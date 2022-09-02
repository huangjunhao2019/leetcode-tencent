package main

import "fmt"

func add(n int) int{
	defer fmt.Println("ok1, n=",n) //在defer入栈的时候，也将相关数据拷贝入栈
	n++
	fmt.Println("ok2,n=",n)
	return n
}

func main(){
	res := add(1)
	fmt.Println("ok3, res=",res)
}