package main

import "fmt"

func main(){
	a := 10
	fmt.Println("açå°å=",&a)

	var ptr *int = &a
	fmt.Println("ptr= ",ptr)
}