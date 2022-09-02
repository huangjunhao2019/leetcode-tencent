package main

import "fmt"

func main(){
	var a []int=[]int{1,3,5,7,9}
	for i := len(a)-1;i>=0;i--{
		fmt.Println(a[i])
	}
}