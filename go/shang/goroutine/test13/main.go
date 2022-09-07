package main

import (
	"fmt"
	"time"
)

func writeData(intChan chan int) {
	for i := 0; i < 50; i++ {
		intChan <- i
		fmt.Println("writeData",i)
		//time.Sleep(time.Second)
	}
	close(intChan)
}
func readData(intChan chan int, exitChan chan bool) {
	for {
		v, ok := <-intChan 
		//表示是否能够成功取出数据，如果管道已经关闭，且为空，ok为false
		if !ok {
			break
		}
		fmt.Printf("readData 读到数据=%v\n", v)
		time.Sleep(time.Second)
	}
	//读取完数据之后，即任务完成
	exitChan <- true
	close(exitChan)
}
func main() {
	//创建两个管道
	intChan := make(chan int, 50)
	exitChan := make(chan bool, 1)
	go readData(intChan, exitChan)
	go writeData(intChan)
	
	for{
		_,ok := <- exitChan
		if !ok{
			break
		}
	}
}
