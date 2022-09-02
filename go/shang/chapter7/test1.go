package main

import "fmt"

func main(){
	//1.定义一个数组
	var hens [6]float64
	hens[0]=1
	hens[1]=2
	hens[2]=3
	hens[3]=4
	hens[4]=5
	hens[5]=6
	//遍历数组求出总体重
	totalWeight := 0.0
	for i:=0;i<len(hens);i++{
		totalWeight+=hens[i]
	}
	avgWeight := fmt.Sprintf("%.2f",totalWeight/float64(len(hens)))
	fmt.Printf("totalWeight=%v avgWeight=%v\n",totalWeight,avgWeight)
}