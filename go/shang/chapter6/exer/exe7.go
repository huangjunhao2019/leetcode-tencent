package main

import (
	"fmt"
	"math/rand"
	"time"
)
func guessNum(n int){
	count := 0
	num := 0
	flag := false
	for i := 0;i<10;i++{
		fmt.Println("请输入你猜的数字(1-100)")
		fmt.Scanln(&num)
		count++
		if(num==n){
			flag = true
			break
		}
	}
	if !flag{
		fmt.Println("说你点啥好呢")
		return
	}
	switch count{
	case 1:
		fmt.Println("你真是个天才")
	case 2,3:
		fmt.Println("你很聪明，快赶上我了")
	case 4,5,6,7,8,9:
		fmt.Println("一般般")
	case 10:
		fmt.Println("可算猜对啦")
	}
}
func main(){
	rand.Seed(time.Now().UnixNano())
	n := rand.Intn(100)+1
	fmt.Println("n=",n)
	guessNum(n)

}