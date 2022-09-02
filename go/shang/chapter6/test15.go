package main

import (
	"fmt"
	"strings"
)

func main(){
	//将左右两边的空格去掉
	str1 := strings.TrimSpace(" tn a lone ")
	fmt.Printf("%q\n",str1)
	//将左右两边的指定字符去掉
	str2 := strings.Trim("! hello ! "," !")
	fmt.Printf("%q\n",str2)
	//将子串左边指定字符去掉
	str3 := strings.TrimLeft("! hello ! ","! ")
	fmt.Printf("%q\n",str3)
	//字符串是否以指定字符串开头或结尾
	var b1 bool = strings.HasPrefix("www.baidu.com","www")
	var b2 bool = strings.HasSuffix("test.jpg",".jpg")
	fmt.Printf("b1=%v, b2=%v\n",b1,b2)
}