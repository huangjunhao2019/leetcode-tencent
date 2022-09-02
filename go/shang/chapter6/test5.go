package main

import "fmt"

func getSum(n1 int,n2 int)(sum int,sub int){
	//不需要担心返回的时候值的顺序
	sum = n1+n2
	sub = n1-n2
	return
}
func main(){
	sum,sub := getSum(100,50)
	fmt.Println("sum=",sum,"sub=",sub)
}