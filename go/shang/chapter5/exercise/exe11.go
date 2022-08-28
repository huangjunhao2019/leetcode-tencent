package main

import "fmt"

func main(){
	var score int64
	fmt.Scanln(&score)
	switch{
	case score>60:
		fmt.Println("合格")
	default:
		fmt.Println("不合格")
	}
}