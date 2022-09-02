package main

import "fmt"

func main(){
	var money float64 = 1e5
	var time int =0
	for {
		if money>=5e4{
			money*=0.95
		} else{
			money-=1000
		}
		if(money<0){
			break
		}
		time++
	}
	fmt.Printf("该人可以通过路口%v次\n",time)
}