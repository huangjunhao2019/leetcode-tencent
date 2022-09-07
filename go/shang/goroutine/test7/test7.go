package main

import(
	"fmt"
)
var myMap=make(map[int]int)
var tempInt=3
func main(){
	for i:=0;i<10;i++{
		myMap[i]=i
	} 
	for index,val := range myMap{
		fmt.Printf("index=%v, val=%v\n",index,val)
	}
}