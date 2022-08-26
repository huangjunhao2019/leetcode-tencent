package main

import (
	"fmt"
	"strconv"
)
//演示golang中string转成基本数据类型
func main(){

	//string转bool
	var str string = "true"
	var b bool
	//1. 函数会返回两个值 (value book, err error)
	//2. 因为我只想获取到value bool，不想获取err，所以使用_忽略err
	b,_= strconv.ParseBool(str)
	fmt.Printf("b type %T b = %v\n",b,b)

	//string转int
	var str2 string = "1234"
	var n1 int64
	n1,_ = strconv.ParseInt(str2,10,64)
	fmt.Printf("n1 type %T n1=%v\n",n1,n1)

	var str3 string = "123.456"
	var f1 float64
	f1,_ = strconv.ParseFloat(str3,64)
	fmt.Printf("f1 type %T f1=%v\n",f1,f1)
}
