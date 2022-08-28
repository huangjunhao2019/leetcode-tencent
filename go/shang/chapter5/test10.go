package main

import "fmt"

func main(){
	//这里演示一下指定标签的形式来使用break
	label2:
	for i:=0;i<4 ;i++{
//		label1: //设置标签，需要冒号
		for j :=0 ;j<10;j++{
			if j==2 {
				break label2//默认breka会跳出最近的for循环
			}
			fmt.Println("j= ",j)
		}
	}
}