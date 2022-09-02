package main

import "fmt"

func main(){
	var alp [26]byte
	for i:=0;i<len(alp);i++{
		alp[i]='A'+byte(i)
	}
	for _,val := range alp{
		fmt.Printf("%c ",val)
	}
	fmt.Println()
}