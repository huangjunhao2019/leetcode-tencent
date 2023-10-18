package main

import (
	"fmt"
)

func putNum(intChan chan int) {
	for i := 1; i < 1000; i++ {
		intChan <- i
	}
	close(intChan)
}
func isPrime(num int) bool {
	if num == 1 {
		return false
	}
	for i := 2; i < num; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}
func putPrime(intChan chan int, primeChan chan int, exitChan chan bool) {
	for {
		num, ok := <-intChan
		if !ok {
			break
		}
		if isPrime(num) {
			primeChan <- num
		}
	}
	fmt.Println("One goroutine exit for no num in intChan")
	exitChan <- true
}
func main() {
	intChan := make(chan int, 1000)
	primeChan := make(chan int, 1000)
	exitChan := make(chan bool, 4)
	go putNum(intChan)
	for i := 0; i < 4; i++ {
		go putPrime(intChan, primeChan, exitChan)
	}
	go func() {
		for i := 0; i < 4; i++ {
			<-exitChan
		}
		close(primeChan)
	}()
	for {
		res, ok := <-primeChan
		if !ok {
			break
		}
		fmt.Println("Prime Num is", res)
	}
	fmt.Println("main goroutine exit.")
}
