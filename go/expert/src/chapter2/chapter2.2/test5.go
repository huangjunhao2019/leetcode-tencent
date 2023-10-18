package main

import "fmt"

func main(){
	v := []int{1,2,3}
	for i:= range v{
		fmt.Println(i)
		v=append(v,i)
	}
}