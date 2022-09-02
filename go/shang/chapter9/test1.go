package main

import "fmt"

func main(){
	//map的声明和注意事项
	var a map[string]string
	a = make(map[string]string,10) //10代表分配了10个空间，后面可以动态变化
	a["no1"]="宋江"
	a["no2"]="吴用"
	fmt.Println(a)
}