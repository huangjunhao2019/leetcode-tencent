package main

import (
	"bufio"
	"fmt"
	"os"
)

func main(){
	//创建一个新文件，写入内容 5句'hello, Gardon"
	filePath := "./res1.txt"
	file,err := os.OpenFile(filePath,os.O_WRONLY | os.O_CREATE,0666)
	if err!=nil{
		fmt.Printf("Open file err=%v\n",err)
		return
	}
	defer file.Close()
	//准备写入5句 "hello, Gardon"
	str := "hello, Gardon\n"
	//写入时，使用带缓存的 *Writer
	writer := bufio.NewWriter(file)
	for i := 0;i<5;i++{
		writer.WriteString(str)
	}
	//因为writer是带缓存，因此在调用WriteStirng时，其实
	//内存是先写到缓存中的，所以需要调用Flush方法，将缓存数据
	//真正写入到文件中，否则文件中会丢失数据
	writer.Flush()
}