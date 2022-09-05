package main

import (
	"fmt"
	_ "fmt"
) //可以用前面加 _ ,来避免未引用问题

type BInterface interface{
	test1()
}
type CInterace interface{
	test2()
}
type AInterface interface{
	BInterface
	CInterace
	test3()
}
//如果我们需要实现AInterface，就需要将BInterface和CInterfac方法都实现
type Stu struct{

}
func (stu Stu) test1(){

}
func (stu Stu) test2(){

}
func (stu Stu) test3(){

}
type T interface{

}

func main(){
	var stu Stu
	var a AInterface = stu
	a.test1()
	var t1 T = stu
	fmt.Println(t1)
	var t2 interface{} = stu
	var num1 float64=8.8
	t2=num1
	fmt.Println(t2)

}