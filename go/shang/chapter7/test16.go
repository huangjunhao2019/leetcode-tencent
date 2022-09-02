package main

import "fmt"

func main(){
	name := [4]string{"白眉鹰王","金毛狮王","紫衫龙王","青翼蝠王"}
	var heroName = ""
	fmt.Println("请输入要查找的人名")
	fmt.Scanln(&heroName)
	index := -1
	for i:=0;i<len(name);i++{
		if heroName == name[i]{
			index = i
			break
		} 
	}
	if index != -1{
		fmt.Printf("找到%v, 下标%v\n",heroName,index)
	} else {
		fmt.Printf("没有找到%v\n",heroName)
	}
}