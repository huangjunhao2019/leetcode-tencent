package main

import "fmt"

func main(){
	//switch穿透fallthrough
	var num int = 10
	switch num{
	case 10:
		fmt.Println("ok1")
		fallthrough //默认只能穿透一层
	case 20:
		fmt.Println("ok2")
	default:
		fmt.Println("没有匹配到...")
	}
	
}