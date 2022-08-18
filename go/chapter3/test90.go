package main

import (
	"fmt"
	"math"
)
func main(){
	var f float32 = 1<<24
	fmt.Println(f)
	fmt.Println(f+1)
	for x := 0;x<8;x++{
		fmt.Printf("x=%d e^x = %8.3e\n",x,math.Exp(float64(x)))
	}
}