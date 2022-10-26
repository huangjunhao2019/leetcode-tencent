package main

import "fmt"

func main(){
	const (
		a = iota
		b
		c
	)
	fmt.Println(a,b,c)
	const (
		a1 = iota
		b1 = iota
		c1,d1 = iota,iota //一行进行递增一次
		e1 = iota
	)
	fmt.Println(a1,b1,c1,d1,e1)
}