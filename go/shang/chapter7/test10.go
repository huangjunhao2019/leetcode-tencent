package main

import (
	"fmt"
)

func main(){
	var strSlice []string =[]string{"tom","jack","mary"}
	fmt.Println("strSlice=",strSlice)
	fmt.Println("strSlice size=",len(strSlice))
	fmt.Println("strSlice cap=",cap(strSlice))
}