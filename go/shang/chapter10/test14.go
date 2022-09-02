package main

import "fmt"

type Calculator struct{
	Num1 float64
	Num2 float64
}
//实现方式1
func (c *Calculator) getSum() float64{
	return c.Num1+c.Num2
}
func (c *Calculator) getSub() float64{
	return c.Num1-c.Num2
}
//实现方式2
func (cal *Calculator) getRes(operator byte) float64{
	res := 0.0
	switch operator{
	case '+':
		res = cal.Num1+cal.Num2
	case '-':
		res = cal.Num1-cal.Num2
	default:
		fmt.Println("运算符输入有误")
	}
	return res
}
func main(){
	var cal Calculator
	cal.Num1=1.2
	cal.Num2=2.2
	fmt.Println("sum=",cal.getSum())
	fmt.Println("sub=",cal.getSub())
	
	res:=cal.getRes('+')
	fmt.Println("res=",res)
}