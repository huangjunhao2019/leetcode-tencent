package main

import "fmt"

func main(){
	var intArr = [...]int{1,-1,9,90,11}
	var maxIndex =0
	var maxVal = intArr[0]
	for i:=1;i<len(intArr);i++{
		if intArr[i]>maxVal{
			maxVal=intArr[i]
			maxIndex=i
		}
	}
	fmt.Printf("maxVal=%v maxIndex=%v\n",maxVal,maxIndex)
}