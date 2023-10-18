package main

import "fmt"

func main(){
	slice := []byte("hello")
	str := string(slice)
	fmt.Println("&slice[0]=",&slice[0],"&str=")
	fmt.Println(str)
	slice[0]='i'
	fmt.Println("&slice[0]=",&slice[0],"&str=",&str)
	fmt.Println(str)
}