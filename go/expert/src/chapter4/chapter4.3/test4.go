package main

import "fmt"

func Fibonacci() func() int{
	a,b := 0,1
	// fmt.Printf("%v %v\n",&a,&b)
	return func() int{
		fmt.Printf("%v %v\n",&a,&b)
		a,b = b,a+b
		return a
	}
}
func main(){
	f := Fibonacci()
	for i:=0;i<10;i++{
		fmt.Println("Fibonacci:",f())
	}
}