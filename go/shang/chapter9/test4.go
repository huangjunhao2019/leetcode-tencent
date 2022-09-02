package main

import "fmt"

func main(){
	//演示map切片的使用
	monsters := make([]map[string]string,2)
	if monsters[0]==nil{
		monsters[0]=make(map[string]string)
		monsters[0]["name"]="牛魔王"
		monsters[0]["age"]="500"
	}
	if monsters[1] == nil{
		monsters[1]=make(map[string]string)
		monsters[1]["name"]="玉兔精"
		monsters[1]["age"]="400"
	}
	//下面这个写法越界了
	// if monsters[2] == nil{
	// 	monsters[1]=make(map[string]string)
	// 	monsters[1]["name"]="狐狸精"
	// 	monsters[1]["age"]="300"
	// }
	//这里我们需要使用到切片的append函数，可以动态增加slice
	//1. 先定义一个monster信息
	newMonster :=map[string]string{
		"name":"新的妖怪",
		"age":"200",
	}
	monsters = append(monsters,newMonster)
	fmt.Println(monsters)
}