package main

import "fmt"

func BubbleSort(a []int,n int){
	for j := 0;j<n-1;j++{
		for i:=0;i<n-1-j;i++{
			if a[i]>a[i+1]{
				temp := a[i]
				a[i] = a[i+1]
				a[i+1] = temp
			}
		}
	}
}
func main(){
	var a = []int{24,69,80,57,13}
	n := len(a)
	fmt.Println("before sort a=",a)
	BubbleSort(a,n)
	fmt.Println("after sort a=",a)
}