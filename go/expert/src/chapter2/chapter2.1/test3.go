package main

import "fmt"

func deferFuncReturn()(result int){
	i := 1
	defer func(){
		result++
	}()
	return i
}
func main(){
	res := deferFuncReturn()
	fmt.Println(res)
}