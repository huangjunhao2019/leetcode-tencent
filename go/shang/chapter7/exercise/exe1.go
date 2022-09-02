package main

import "fmt"

func fbn(slice []int, n int){
	if n==1{
		slice[0]=1
		return
	}
	slice[0]=1
	slice[1]=1
	for i := 2;i<n;i++{
		slice[i]=slice[i-1]+slice[i-2]
	}
}
func main(){
	n := 10
	slice := make([]int,n)
	fbn(slice,n)
	fmt.Println("slice=",slice)
}