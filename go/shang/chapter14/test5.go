package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)
func main(){
	//打开一个已经存在的文件，将原来的内容覆盖成新的内容"你好，尚硅谷“
	filePath := "./res1.txt"
	file,err := os.OpenFile(filePath,os.O_RDWR | os.O_APPEND,0666)
	if err!=nil{
		fmt.Printf("open file err=%v\n",err)
		return 
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	for {
		str,err := reader.ReadString('\n')
		if err == io.EOF{
			fmt.Print(str)
			break
		}
		fmt.Print(str)
	}
	str := "hello, 北京\n"
	writer := bufio.NewWriter(file)
	for i:=0;i<5;i++{
		writer.WriteString(str)
	}
	writer.Flush()
}