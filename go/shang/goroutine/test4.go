package main

import(
	"fmt"
	"time"
)
//思路：
// 1. 编写一个函数，来计算各个数的阶乘，并放入到map中
// 2. 我们启动的协程多个，统一将阶乘结果放入到map中
// 3. map应该做成全局的

func test(n int)  {
	res := 1
	for i:=1;i<=n;i++{
		res*=i
	}
	fmt.Printf("%v!=%v\n",n,res)
}
func main(){
	fmt.Println("prgram start")
	for i:=1;i<5;i++{
		go test(i)
	}
	time.Sleep(2*time.Second)
	fmt.Println("program end")
}