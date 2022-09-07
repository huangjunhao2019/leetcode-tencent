package main

import(
	"fmt"
)
func addUpper(n int) int{
	res := 0
	for i:=1;i<=n;i++{
		res+=i
	}
	return res
}
func main(){
	//传统测试方法，就是在main函数中使用addUpper，看看结果是否正确
	res := addUpper(10) //1+...+10=55 
	fmt.Printf("addUpper 返回值=%v 期望值=%v\n",res,55)
}