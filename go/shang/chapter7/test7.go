package main

import "fmt"

func main(){
	var intArr=[...]int{1,2,2}
	sum :=0
	for _,val := range intArr{
		sum+=val
	}
	fmt.Printf("sum=%v average=%v\n",sum,float32(sum)/float32(len(intArr)))
}