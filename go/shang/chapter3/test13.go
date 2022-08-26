package main

import(
	"fmt"
	"strconv"
)

func main(){
	var str string = "hello"
	var n int64
	n,_ =strconv.ParseInt(str,10,0)
	fmt.Printf("n type %T n=%v\n",n,n)
}