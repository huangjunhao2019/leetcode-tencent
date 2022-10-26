package main

import "fmt"

func main(){
	a := "hello"
	for _,val := range a{
		fmt.Printf("%T\n",val)
	}
}