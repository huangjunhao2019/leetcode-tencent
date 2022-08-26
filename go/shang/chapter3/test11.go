package main

import (
	"fmt"
	"strconv"
)

func main(){
	var num1 int =99
	var num2 float64 = 23.456
    var b bool = true
	var str string
	//使用第二种方式转换
	str = strconv.FormatInt(int64(num1),10)
	fmt.Printf("str type = %T str=%q\n",str,str)

	str = strconv.Itoa(num1)

	//说明：'f' 格式 10: 表示小数位保留10位 64：表示这个小数是float64
	str = strconv.FormatFloat(num2,'f',10,64)
	fmt.Printf("str type = %T str=%q\n",str,str)

	str = strconv.FormatBool(b)
	fmt.Printf("str type = %T str=%q\n",str,str)
}