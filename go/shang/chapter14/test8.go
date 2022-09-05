package main

import (
	"bufio"
	"fmt"
	"io" 
	"os"
)
func CopyFile(dstFileName string,srcFileName string)(writen int64,err error){
	srcFile,err := os.Open(srcFileName)
	if err!=nil{
		fmt.Printf("open file error=%v\n",err)
	}
	defer srcFile.Close()
	//通过srcFile，获取到reader
	reader:=bufio.NewReader(srcFile)

	//打开dstFileName
	dstFile,err := os.OpenFile(dstFileName,os.O_WRONLY | os.O_CREATE,0666)
	if err!=nil{
		fmt.Printf("open file err=%v\n",err)
		return 
	}
	defer dstFile.Close()
	//通过dstFile获取writer
	writer := bufio.NewWriter(dstFile)
	return io.Copy(writer,reader)
}
func main(){
	//将./dir1/flower1.jpg 拷贝到 ./dir2/中
	_,err:=CopyFile("./dir2/flower2.jpg","./dir1/flower.jpg")
	if err==nil{
		fmt.Println("拷贝完成")
	} else{
		fmt.Printf("err=%v",err)
	}
}