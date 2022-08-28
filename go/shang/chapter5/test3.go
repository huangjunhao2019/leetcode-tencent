package main

import(
	"fmt"
	"math"
)

func main(){
	var a,b,c float64 = 3,100,6
	m := b*b-4*a*c
	if m > 0{
		x1 := (-b+math.Sqrt(m))/(2*a)
		x2 := (-b-math.Sqrt(m))/(2*a)
		fmt.Printf("x1= %v x2= %v\n",x1,x2)
	} else if m==0 {
		x1 := (-b)/(2*a)
		fmt.Printf("x1= %v\n",x1)
	} else{
		fmt.Println("无解...")
	}

}