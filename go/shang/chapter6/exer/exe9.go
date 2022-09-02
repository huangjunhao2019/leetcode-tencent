package main

import "fmt"

func printAlpha(begin byte,end byte){
	if begin<end{
		for i:=begin;i<=end;i++{
			fmt.Printf("%c ",i)
		}
		fmt.Println()
	} else {
		for i:=begin;i>=end;i--{
			fmt.Printf("%c ",i)
		}
		fmt.Println()
	}
}
func main(){
	printAlpha('a','z')
	printAlpha('Z','A')
}