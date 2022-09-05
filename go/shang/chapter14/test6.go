package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	// twoCity.txt --> res1.txt
	//1. 首先将twoCity.txt读取到内存
	//2. 将读取到的内容写入到res1.txt
	file1Path := "./twoCity.txt"
	file2Path := "./res1.txt"
	content, err := ioutil.ReadFile(file1Path)
	if err != nil {
		fmt.Printf("read file err=%v\n", err)
		return
	}
	err2 := ioutil.WriteFile(file2Path, content, 0666)
	if err2 != nil {
		fmt.Println("写文件出错")
	}

}
