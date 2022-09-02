package main

import "fmt"

func swap(n1 *int,n2 *int){
	temp := *n1
	*n1 = *n2
	*n2 = temp
}
func main(){
	n1 := 10
	n2 := 20
	swap(&n1,&n2) //要传地址
	fmt.Println("n1=",n1,"n2=",n2)
}