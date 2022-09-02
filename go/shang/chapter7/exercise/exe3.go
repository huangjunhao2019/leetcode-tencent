package main

import (
	"fmt"
)
func insert(arr []int,val int) []int{
	left := 0
	right := len(arr)-1
	for left+1<right{
		mid := left+(right-left)/2
		if arr[mid]>=val{
			right=mid
		} else{
			left=mid
		}
	}
	arr = append(arr,val)
	for i := len(arr)-2;i>=right;i--{
		arr[i+1]=arr[i]
	}
	arr[right]=val
	return arr
}
func main(){
	var arr []int=[]int{1,3,5,7,9}
	fmt.Println("插入前: arr=",arr)
	arr=insert(arr,4)
	fmt.Println("插入后: arr=",arr)
}