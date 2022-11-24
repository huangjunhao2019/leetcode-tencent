package  main

import (
	"fmt"
	"os"
)

func main(){
	list := os.Args
	if len(list)!=2{
		fmt.Println("the argument number should be 2")
		return 
	}
	fileName := list[1]

	fileInfo,err := os.Stat(fileName)
	if err!=nil{
		fmt.Println("err=",err)
		return 
	}
	fmt.Println("name = ",fileInfo.Name())
	fmt.Println("size = ",fileInfo.Size())
}