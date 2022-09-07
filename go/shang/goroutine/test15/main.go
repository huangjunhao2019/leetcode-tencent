package main

import (
	"fmt"
	"time"
)
func putNum(intChan chan int){
	for i:=1;i<=80000;i++{
		intChan<-i
	}
	//关闭intCha
	close(intChan)
}
func primeNum(intChan chan int,primeChan chan int,exitChan chan bool){
	for{
		//time.Sleep(100*time.Millisecond)
		num,ok := <- intChan
		flag := true
		if !ok{
			break
		}
		for i:=2;i<num;i++{
			if num%i==0{
				flag=false
				break
			}
		}
		if num==1{
			flag=false
		}
		if flag{
			primeChan<-num
		}
	}
	// fmt.Println("有一个primeNum协程因为取不到数据，退出")
	//这里还不能关闭primeChan，有可能别的协程正在ongoing
	exitChan<-true
}
func main(){
	intChan := make(chan int,1000)
	primeChan := make(chan int,2000)

	exitChan := make(chan bool,4)
	start := time.Now().UnixMilli()
	//开启一个协程，向intChan放入1-8000个数
	go putNum(intChan)
	//开启4个协程，从intChan取出数据，并判断是否为素数
	//如果是，就放入到primeChan
	for i:=0;i<4;i++{
		go primeNum(intChan,primeChan,exitChan)
	}
	//这里主线程，进行处理
	go func(){
		for i:=0;i<4;i++{
			<-exitChan
		}
		end := time.Now().UnixMilli()
		fmt.Println("使用协程耗时=",end-start)
		//当我们从这个管道取出4个结果，就可以放心关闭primeChan
		close(primeChan)
	}()
	for{
		// res,ok := <- primeChan
		_,ok := <- primeChan
		if !ok{
			break
		}
		// fmt.Printf("素数=%v\n",res)
	}
	fmt.Println("main线程退出")
}