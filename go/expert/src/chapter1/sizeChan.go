package main

import "fmt"

func main(){
	ch := make(chan int,10)
	fmt.Println("len(ch)=",len(ch),"cap(ch)",cap(ch))
}