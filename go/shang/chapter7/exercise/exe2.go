package main

import (
	"fmt"
	"math/rand"
	"time"
)
func main(){
	var arr [10]int
	rand.Seed(time.Now().UnixNano())
	sumAll := 0.0
	for i:=0;i<10;i++{
		arr[i]=rand.Intn(100)+1
		sumAll+=float64(arr[i])
	}
	fmt.Println("反转前",arr)
	for i:=len(arr)-1;i>=0;i--{
		fmt.Printf("%v ",arr[i])
	}
	fmt.Println()
	fmt.Printf("平均值=%v\n",sumAll/float64(len(arr)))
	
	maxVal := arr[0]
	maxIndex := 0
	minVal := arr[0]
	minIndex := 0
	for index,val := range arr{
		if val>maxVal{
			maxVal=val
			maxIndex=index
		}
		if val < minVal{
			minVal=val
			minIndex=index
		}
	}
	fmt.Printf("最大值为%v, 最大值下标为%v\n",maxVal,maxIndex)
	fmt.Printf("最小值为%v，最小值下标为%v\n",minVal,minIndex)
}