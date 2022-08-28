package main

import "fmt"

func main(){
	var huashi float32 = 200
	var sheshi float32 = 5.0/9 *(huashi-100)
	fmt.Printf("%v 对应的摄氏温度为%v\n",huashi,sheshi)
}