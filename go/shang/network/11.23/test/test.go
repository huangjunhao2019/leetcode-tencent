package main

import (
	"fmt"
)

func writeNum(ch chan int) {
	for i := 0; i < 10; i++ {
		ch <- i
		fmt.Println("chan val=", i)
	}
	close(ch)
}
func readNum(ch chan int, exitChan chan bool) {
	for {
		v, ok := <-ch
		if !ok {
			break
		}
		fmt.Println("val=", v)
	}
	exitChan <- true
}
func main() {
	ch := make(chan int, 3)
	exitChan := make(chan bool, 3)
	defer close(exitChan)
	go writeNum(ch)
	for i := 0; i < 3; i++ {
		go readNum(ch, exitChan)
	}
	count := 0
	for {
		_, ok := <-exitChan
		if !ok {
			break
		}
		count++
		if count == 3 {
			break
		}
	}
}
