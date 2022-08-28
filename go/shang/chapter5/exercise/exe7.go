package main

import "fmt"

func main(){
	var num1 int = 12
	var num2 int = 3
	var sum int = num1 + num2
	if sum % 3 ==0 && sum % 5 == 0{
		fmt.Println("3 ok, 5 ok")
	}
}