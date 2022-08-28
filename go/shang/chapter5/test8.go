package main

import "fmt"

func main(){
	//字符串遍历方式1
	var str string = "hi 北京"
	str2 :=[]rune(str)
	for i := 0;i<len(str2);i++{
		fmt.Printf("%c",str2[i])//输出乱码，中文显示为编码
	}
	fmt.Println()
	//字符串遍历方式2 for-range方式
	str3 := "hi, 上海"
	for index,val := range str3{
		fmt.Printf("index=%d val=%c\n",index,val)
	}
	fmt.Println()
}