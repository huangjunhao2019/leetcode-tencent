package main

import "fmt"

func main(){
	fmt.Println(2&3) //2
	fmt.Println(2|3) //3
	fmt.Println(13&7) //5
	fmt.Println(5 | 4) // 5
	fmt.Println(-3^3) //-2
	fmt.Println(-1 ^ -2) //1,即使是符号位也参与运算
}