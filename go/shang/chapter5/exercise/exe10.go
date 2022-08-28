package main

import "fmt"

func main(){
	var ch byte
	fmt.Println("请输入char")
	fmt.Scanf("%c",&ch) //用Scanln不行
	switch ch{
	case 'a': 
		fmt.Printf("A")
	case 'b': 
		fmt.Printf("B")
	case 'c': 
		fmt.Printf("C")
	case 'd': 
		fmt.Printf("D")
	case 'e': 
		fmt.Printf("E")
	default:
		fmt.Println("other")
	}
}