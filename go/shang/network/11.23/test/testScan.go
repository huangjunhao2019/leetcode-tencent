package main

import "fmt"

func main(){
	var name string
	for {
		fmt.Println("hello")
		fmt.Scanln(&name)
	}
}