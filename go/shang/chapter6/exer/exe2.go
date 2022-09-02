package main

import "fmt"
func f(n int) int{
	if n==1{
		return 3
	}
	return 2*f(n-1)+1
}
func main(){
	var n int =4
	fmt.Printf("f(%v) = %v\n",n,f(n))
}