package main

import "fmt"

func main(){
	mp := make(map[int]int)
	if mp[0]==0{
		fmt.Println("hello")
	}
	fmt.Println(len(mp))
}