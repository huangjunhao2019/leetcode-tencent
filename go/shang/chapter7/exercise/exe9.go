package main

import "fmt"
func findMaxMin(a [5]int)(int,int){
	maxIndex := 0
	minIndex := 0
	for i :=1;i<len(a);i++{
		if a[i]>a[maxIndex]{
			maxIndex=i
		}
		if a[i]<a[minIndex]{
			minIndex=i
		}
	}
	return maxIndex,minIndex
}
func main(){
	var a [5]int = [5]int{5,6,3,2,10}
	maxIndex,minIndex := findMaxMin(a)
	fmt.Println("maxIndex=",maxIndex,"minIndex=",minIndex)
}