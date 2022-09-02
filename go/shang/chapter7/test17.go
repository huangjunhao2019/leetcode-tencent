package main

import ( 
	"fmt"
)

//二分查找的方法
func BinaryFind(arr []int,left int,right int,findVal int){
	if left>right{
		fmt.Println("找不到")
		return
	}
	mid := (left+right)/2
	if findVal<arr[mid]{
		//说明我们查找的数，应该在 left -- mid-1
		BinaryFind(arr,left,mid-1,findVal)
	} else if(findVal>arr[mid]){
		BinaryFind(arr,mid+1,right,findVal)
	} else{
		fmt.Printf("找到了下标为%v\n",mid)
	}
}
func main(){
	var arr []int=[]int{1,8,10,89,1000,1234}
	BinaryFind(arr,0,len(arr)-1,89)
}