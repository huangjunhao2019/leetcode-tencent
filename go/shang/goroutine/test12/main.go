package main

import "fmt"

func main(){
	intChan := make(chan int,3)
	intChan <- 100
	intChan <- 200
	close(intChan)
	//这时不能再写入数据到channel
	//intChan <- 300 //此处会进行报错
	fmt.Println("ok~~~")
	n1 := <- intChan

	fmt.Println("n1=",n1)

	//遍历管道
	intChan2 := make(chan int,100)
	for i:=0;i<100;i++{
		intChan2 <- i*2 //放入100个数据到管道
	}
	//遍历管道时，不能使用普通的for循环，应该用for-range方式
	// for i := 0;i<len(intChan2);i++{
	// 	fmt.Println(<- intChan2) //只能取出来50个，因为每次取出数据，len(intChan2)都会变化
	// }
	//如果在遍历时，没有关闭，则会出现deadlock
	close(intChan2)
	for v := range intChan2{
		fmt.Println("v=",v)
	}
}