package main

import "fmt"
func swap(a *int,b *int){
	temp := *a
	*a = *b
	*b = temp
}
func main(){
	var a [4][4]int
	for i:=0;i<len(a);i++{
		for j:=0;j<len(a[i]);j++{
			fmt.Scanf("%d",&a[i][j])
		}
	}
	for i:=0;i<len(a)/2;i++{
		for j:=0;j<len(a[i]);j++{
			swap(&a[i][j],&a[len(a)-1-i][j])
		}
	}
	for _,val := range(a){
		fmt.Println(val)
	}
}