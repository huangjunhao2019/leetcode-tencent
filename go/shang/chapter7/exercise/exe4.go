package main

import "fmt"

func main(){
	var a [3][4]int 
	for i:=0;i<len(a);i++{
		for j:=0;j<len(a[i]);j++{
			fmt.Scanf("%d",&a[i][j])
		}
	}
	for i:=0;i<len(a);i++{
		for j:=0;j<len(a[i]);j++{
			if i==0 || i==len(a)-1 || j==0 || j==len(a[i])-1{
				a[i][j]=0
			}
		}
	}
	fmt.Println("a=",a)
}