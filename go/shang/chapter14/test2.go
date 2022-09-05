package main

import (
	"fmt"
	"os"
	"bufio"
	"io"
)
func main(){
	file,err := os.Open("./twoCity.txt")
	if err != nil{
		fmt.Println("open file err=",err)
	}
	//当函数结束时，要及时关闭file
	defer file.Close()//要及时关闭file句柄
	//否则会有内存泄漏
	//创建一个 *Reader, 带缓存的
	/*
	默认缓冲区是4096
	*/
	reader := bufio.NewReader(file)
	for{
		str,err := reader.ReadString('\n') //读到一个换行符就算一次
		if err == io.EOF{ //表示读到文件末尾
			fmt.Print(str)
			break
		}
		fmt.Print(str)
	}
	fmt.Println("文件读取结束")
}