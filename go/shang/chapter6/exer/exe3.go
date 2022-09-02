package main

import "fmt"

func peach(n int) int{
	if n==10{
		return 1
	} else {
		return (peach(n+1)+1)*2
	}
}
func main(){
	var n int =1
	fmt.Println("The num of peaches",peach(n))
}