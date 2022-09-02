package main

import "fmt"

func fib(n int) int{
	if n==1 || n==2{
		return 1
	}
	return fib(n-1)+fib(n-2)
}
func main(){
	var n int = 4
	fmt.Printf("fib(%v) = %v\n",n,fib(n))
}