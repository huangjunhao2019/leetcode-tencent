package main

import "fmt"

func main(){
	var numArr1 [3]int=[3]int{1,2,3}
	fmt.Println("numArr1=",numArr1)
	var numArr2 = [3]int{4,5,6}
	fmt.Println("numArr2=",numArr2)
	var numArr3 = [...]int{8,9,10}
	fmt.Println("numArr3=",numArr3)
	var numArr4 =[...]int{1:800,0:900,2:999}
	fmt.Println("numArr4=",numArr4)
	numArr5 := [...]string{1:"tom",0:"jack",2:"mary"}
	fmt.Println("numArr5=",numArr5)
}