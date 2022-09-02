package main

import "fmt"
func test02(arr *[3]int){
	(*arr)[0]=88
}
func main() {
	var arr [3]int=[3]int{0,0,0}
	test02(&arr)
	fmt.Println(arr)
}
