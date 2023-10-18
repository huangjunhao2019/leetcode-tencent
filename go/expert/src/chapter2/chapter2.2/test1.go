package main

import (
	"fmt"
	"time"
)

func main(){
	chan1 := make(chan int)
	chan2 := make(chan int)
	fmt.Println(len(chan1))

	go func(){
		chan1 <- 1
		time.Sleep(5*time.Second)
	}()
	go func(){
		chan2 <- 1
		time.Sleep(5*time.Second)	
	}()
	time.Sleep(1*time.Second)
	select{
	case <- chan1:
		fmt.Println("chan1 ready.")
	case <- chan2:
		fmt.Println("chan2 ready.")
	default:
		fmt.Println("default.")
	}
	fmt.Println("main exit")
}