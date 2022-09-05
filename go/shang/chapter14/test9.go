package main

import(
	"fmt"
	"os"
	"io"
	"bufio"
)
//定义一个结构体，用于保存统计结果
type CharCount struct{
	CharCount int
	NumCount int
	SpaceCount int
	OtherCount int
}
func main(){
	/*
	*思路：打开一个文件，创建一个Reader
	*每读取一行，就去统计改行有多少个 英文、数字、空格和其他字符
	*然后将结果保存到一个结构体
	*/
	filePath := "./twoCity.txt"
	file,err := os.Open(filePath)
	if err !=nil{
		fmt.Printf("open file err=%v\n",err)
		return
	}
	defer file.Close()
	var count CharCount
	reader := bufio.NewReader(file)
	for{
		str,err := reader.ReadString('\n')
		if err == io.EOF{
			break
		}
		strRune := []rune(str)
		//遍历str，进行统计
		for _,v := range strRune{
			switch {
			case v>='a' && v<='z':
				fallthrough
			case v>='A' && v<='Z':
				count.CharCount++
			case v ==' ' || v=='\t':
				count.SpaceCount++
			case v>='0' && v<='9':
				count.NumCount++
			default:
				count.OtherCount++
			}
		}
	}
	fmt.Println(count)
}