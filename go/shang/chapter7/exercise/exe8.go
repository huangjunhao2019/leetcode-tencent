package main

import (
	"fmt"
	"math/rand" 
	"time"
)
func swap(a *int,b *int){
	temp := *a
	*a = *b
	*b = temp
}
func bubble_sort(a []int){
	n := len(a)
	for i := 0;i<n-1;i++{
		for j:=0;j<n-i-1;j++{
			if a[j]>a[j+1]{
				swap(&a[j],&a[j+1])
			}
		}
	}
}
func partition(a []int,left int,right int) int {
	pivot := a[left]
	for left<right {
		for left<right && a[right]>=pivot{
			right--
		}
		a[left]=a[right]
		for left<right && a[left]<=pivot{
			left++
		}
		a[right]=a[left]
	}
	a[left]=pivot
	return left
}
func quick_sort(a []int,left int,right int){
	if left < right{
		loc := partition(a,left,right)
		quick_sort(a,left,loc-1)
		quick_sort(a,loc+1,right)
	}
}
func main(){
	var a []int=make([]int,100)
	var b []int=make([]int,100)
	rand.Seed(time.Now().UnixNano())
	for i:=0;i<100;i++{
		a[i]=rand.Intn(100)+1
		b[i]=a[i]
	}
	t1 := time.Now().UnixNano()
	bubble_sort(a)
	t2 :=time.Now().UnixNano()
	quick_sort(b,0,len(b)-1)
	t3 := time.Now().UnixNano()
	fmt.Println("a=",a)
	fmt.Println("b=",b)
	fmt.Println("bubble_sort time = ",t2-t1,"quick_sort time = ",t3-t2)

}