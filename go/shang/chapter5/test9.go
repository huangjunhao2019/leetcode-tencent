package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main(){
	//如何随机生成1-100的数
	//为了生成随机数，还需要给rand设置一个种子
	//time.Now().Unix()：返回从1970:1:1/0:0:0到现在的秒数
	// fmt.Println(time.Now().Unix())
	// rand.Seed(time.Now().Unix())
	// n := rand.Intn(100)+1
	// fmt.Println(n)
	var count int = 0
	for{
		rand.Seed(time.Now().UnixNano())//用Unix()不太随机，改成纳米就快了
		n := rand.Intn(100)+1
		fmt.Println("n=",n)
		count++
		if n == 99{
			break
		}
	}
	fmt.Println("count= ",count)
}