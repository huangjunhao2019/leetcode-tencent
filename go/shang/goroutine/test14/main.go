package main

import (
	"fmt"
	"time"
)
func writeNum(numChan chan int){
	for i:=1;i<=10;i++{
		numChan <- i
	}
	close(numChan)
}
func readNum(numChan chan int,resChan chan int,exitChan chan bool){
	for {
		v,ok := <- numChan
		if !ok{
			break
		}
		resChan <- v
	}
	exitChan <- true
 
}
func main(){
	var numChan chan int
	numChan = make(chan int,2000)
	resChan := make(chan int,2000)
	exitChan := make(chan bool,8)
	go writeNum(numChan)
	for i:=0;i<8;i++{
		go readNum(numChan,resChan,exitChan)
	}
	count := 0
	for{
		_,ok := <- exitChan
		if !ok {
			break
		}
		count++
		if(count==8){
			break
		}
	}
	time.Sleep(10*time.Second)
	close(exitChan)
	close(resChan)
	index := 0
	for val := range resChan{
		fmt.Printf("res[%v]=%v\n",index,val)
		index++
	}
}