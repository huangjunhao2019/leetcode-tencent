package main

import "fmt"

func main(){
	//演示一下管道的使用
	//1. 创建一个可以存放3个int类型的管道
	var intChan chan int
	intChan = make(chan int,3) //此处指定的是它的cap，不是len
	
	//2. 查看intChan是什么
	fmt.Printf("intChan=%v, channel本身的地址为=%p\n",intChan,&intChan)
	//3. 向管道写入数据
	intChan <- 10
	num := 211
	intChan <- num
	intChan <- 50
	//intChan <- 20 //报错，管道容量为3，不能超过3
	//4. 查看管道的长度和cap（容量）
	fmt.Printf("channel len=%v  cap=%v \n",len(intChan),cap(intChan))

	//5. 从管道中读取数据
	var num2 int
	num2 = <- intChan
	fmt.Println("num2=",num2)
	fmt.Printf("channel len=%v  cap=%v \n",len(intChan),cap(intChan))
}