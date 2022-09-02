package main

import "fmt"
type MethodUtils struct{

}
func (mu *MethodUtils) Print1(){
	var n int
	fmt.Scanln(&n)
	for i:=1;i<=n;i++{
		for j:=1;j<=i;j++{
			fmt.Printf("%v * %v = %v\t",j,i,j*i)
		}
		fmt.Println()
	}
}
func (mu *MethodUtils) change(a [][]int){
	m := len(a) 
	for i:=0;i<m;i++{
		for j:=0;j<i;j++{
			temp := a[i][j]
			a[i][j]= a[j][i]
			a[j][i]=temp
		}
	}
}
func main(){
	var mu MethodUtils
	mu.Print1()
	var slices = [][]int{{1,2,3},{4,5,6},{7,8,9}}
	mu.change(slices)
	fmt.Println("slices=",slices)
}