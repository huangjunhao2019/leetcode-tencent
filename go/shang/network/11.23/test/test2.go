package main

import "fmt"

func main(){
	num := make([]int ,10)
	ch := make(chan int,10)
	fmt.Println("len(num)=",len(num),"cap(num)=",cap(num))
	fmt.Println("len(ch)=",len(ch),"cap(num)",cap(num))
	ch<-1
	fmt.Println("len(ch)=",len(ch),"cap(num)",cap(num))
}