package main

import "fmt"
type MethodUtils struct{

}
func (mu *MethodUtils) Print(n int,m int,key byte){
	for i:=0;i<n;i++{
		for j:=0;j<n;j++{
			fmt.Printf("%c",key)
		}
		fmt.Println()
	}
}
func (mu *MethodUtils) JudgeNum(num int){
	if num % 2==0{
		fmt.Printf("%v是偶数\n",num)
	} else{
		fmt.Printf("%v是奇数\n",num)
	}
}
func main(){
	var me MethodUtils

	me.JudgeNum(3)
	me.Print(3,2,'+')
}