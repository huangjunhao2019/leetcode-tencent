package main

import "fmt"

func main(){
	var a []int = []int{1,2,3,4,5}
	var slice = make([]int,10)
	fmt.Println(slice)

	copy(slice,a)
	fmt.Println(slice)
	//a与slice两个切片是独立的，两个是独立的空间
	a[0]=100 //改变a，不会影响slice
	fmt.Println("a=",a)
	fmt.Println("slice=",slice)
}