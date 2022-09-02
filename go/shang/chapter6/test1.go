package  main

import "fmt"

//将计算的功能放到一个函数里面，在需要使用时，调用即可
func cal(n1 float64,n2 float64, operator byte) float64{
	var res float64
	switch operator {
	case '+':
		res=n1+n2
	case '-':
		res=n1-n2
	case '*':
		res=n1*n2
	case '/':
		res=n1/n2
	default:
		fmt.Println("操作符号错误...")
	}
	return res
}
func main(){
	var n1 float64 =1.2
	var n2 float64 =2.3
	var operator byte = '*'
	var res float64
	res=cal(n1,n2,operator)
	fmt.Println("res= ",res)
}