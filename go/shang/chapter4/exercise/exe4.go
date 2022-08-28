package main

import "fmt"

func main(){
	var a int = 10
	var b int = 20
	var c int = 30
	if a>=b && a>=c{
		fmt.Println(" max = ",a)
	} else if b >= a && b >= c{
		fmt.Println("max = ",b)
	} else {
		fmt.Println("max = ",c)
	}
}