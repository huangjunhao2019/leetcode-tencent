package main

import "fmt"

func main(){
	var arr [10]string=[10]string{"one","two","three",
	"four","five","six","seven","eight","nine","ten"}
	findVal := "fou"
	loc := make([]int,0)
	for index,val := range arr{
		if val == findVal{
			loc=append(loc,index)
		}
	}
	if len(loc)==0{
		fmt.Println("not found")
	}
	for _,val := range loc{
		fmt.Println(val)
	}
}