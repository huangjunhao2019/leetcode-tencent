package main

import(
	"fmt"
	"os"
)

func main(){
	//打开文件
	//file的叫法
	//1. file叫file对象
	//2. file叫file指针
	//3. file叫file文件句柄
	file,err := os.Open("./twoCity.txt")
	if err!=nil{
		fmt.Println("Open file err=",err)
	}
	fmt.Printf("file=%v\n",file) //file是一个指针，输出为地址
	err =file.Close()
	if err!=nil{
		fmt.Println("close file err=",err)
	}
}