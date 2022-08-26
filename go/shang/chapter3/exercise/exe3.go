package main

import (
	"fmt"
)

func main(){
	var num int = 100
	var ptr *int = &num
	fmt.Printf("num 的地址为 %v\n",ptr)
	*ptr = 200
	fmt.Printf("num的值为 %v\n",num)
}