package main

import "fmt"

func main(){
	a := 10
	fmt.Println("a的地址=",&a)

	var ptr *int = &a
	fmt.Println("ptr= ",ptr)
}