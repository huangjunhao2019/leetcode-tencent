package main

import (
	"fmt"
	"time"
)

var (
	myMap = make(map[int]int,0) //此处空间大小改成21，也不会出问题
	// mySlice = make([]int,22)
)

func test(n int){
	res := 1
	for i:=1;i<=n;i++{
		res *=i
	}
	myMap[n]=res
	// mySlice[n]=res
}
func main(){
	for i:=1;i<=40;i++{
		go test(i)
	}
	time.Sleep(time.Second*5)
	for i,v := range myMap{
		fmt.Printf("map[%v]=%v\n",i,v)
	}
	// for index,val := range mySlice{
		//这种方法不会出现写冲突，原因在于slice没有动态变化，
		//而map一直在随着操作，而增加元素，存在复制，增加容量，改变地址的问题
	// 	fmt.Printf("slice[%v]=%v\n",index,val) 
	// }
}