package main

import "fmt"

type Integer int
func main(){
	var i Integer = 10
	var j int = 20
	j = i//错误，程序认为i与j是两种类型，改成 j=int(i)即可
	fmt.Print(i,j)
}