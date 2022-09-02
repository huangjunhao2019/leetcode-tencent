package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main(){
	var intArr [5]int
	rand.Seed(time.Now().UnixNano())
	for i:=0;i<len(intArr);i++{
		intArr[i]=rand.Intn(100)
	}
	fmt.Println("交换前=",intArr)
	var temp int
	for i:=0;i<len(intArr)/2;i++{
		temp=intArr[len(intArr)-1-i]
		intArr[len(intArr)-1-i]=intArr[i]
		intArr[i]=temp
	}
	fmt.Println("交换后=",intArr)
}