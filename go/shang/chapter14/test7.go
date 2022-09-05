package main

import (
	"fmt"
	"os"
)
func PathExists(path string)(bool,error){
	_,err := os.Stat(path)
	if err == nil{
		return true,nil
	}
	if os.IsNotExist(err){
		return false,nil
	}
	return false,err
}
func  main(){
	flag,err:=PathExists("/home/huang/")
	fmt.Println(flag,err)
	flag,err=PathExists("./res1.txt")
	fmt.Println(flag,err)
}