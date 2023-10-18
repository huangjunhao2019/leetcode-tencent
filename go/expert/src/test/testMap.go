package main

import "fmt"

func main(){
	mp := make(map[int]int)
	_,ok := mp[0]
	fmt.Println(ok,len(mp))
}