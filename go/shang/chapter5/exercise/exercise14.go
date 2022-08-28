package main

import "fmt"

func main(){
	count := 0
	res := 0
	for i := 1;i<=100;i++{
		if i%9==0{
			count++
			res+=i
		}
	}
	fmt.Printf("共有%v个9的倍数，和是%v\n",count,res)
}