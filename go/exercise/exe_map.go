package main

import "fmt"

func main(){
	mp := make(map[int]int)
	for i:=0;i<10;i++{
		fmt.Printf("mp[%v]=%v\n",i,mp[i])
	}
}