package main

import (
	"fmt"
)
//演示golang中基本数据类型的转换
func main() {
	var num1 int64 = 999999
	var num2 int8 = int8(num1) //直接进行截断处理的
	fmt.Println(num1,num2)

}
