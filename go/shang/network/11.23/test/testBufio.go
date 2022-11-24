package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main(){
	file,_ := os.Open("./hello")
	reader := bufio.NewReader(file)
	for{
		str,_,err := reader.ReadLine()
		if err!=nil{
			if err==io.EOF{
				fmt.Println("finish")
			}
			return 
		}
		fmt.Println(string(str))
	}
}