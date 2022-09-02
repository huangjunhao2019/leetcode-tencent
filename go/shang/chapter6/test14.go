package main

import "fmt"

func PrintMulti(n int){
	for i := 1;i<=n;i++{
		for j := 1;j<=i;j++{
			fmt.Printf("%v * %v = %v\t",j,i,i*j)
		}
		fmt.Println()
	}
}
func main(){
	var n int
	fmt.Scanln(&n)
	PrintMulti(n)
}