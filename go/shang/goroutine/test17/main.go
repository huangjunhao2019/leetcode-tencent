package main

import (
	"fmt"
	"time"
)

func sayHello(){
	for i:=0;i<10;i++{
		time.Sleep(time.Second)
		fmt.Println("Hello, world")
	}
}
func test(){
	var myMap map[int]string //这里没有map，所以会崩溃
	//这里使用defer + recover
	defer func(){
		//捕获test抛出的panic
		if err := recover();err!=nil{
			fmt.Println("test() 发生错误")
		}
	}()
	myMap[0]="golang"
}
func main(){
	go sayHello()
	go test()
	for i:=0;i<10;i++{
		fmt.Println("main() ok=",i)
		time.Sleep(time.Second)
	}
}