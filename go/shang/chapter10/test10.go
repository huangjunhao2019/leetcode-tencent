package main

import "fmt"
type Person struct{
	Name string
}
func (p Person) speak(){
	fmt.Printf("%v是一个好人\n",p.Name)
}
func (p Person) jisuan(){
	res := 0
	for i:=1;i<=1000;i++{
		res+=i
	}
	fmt.Println(p.Name,"计算的结果=",res)
}
func (p Person) jisuan2(n int){
	res := 0
	for i:=1;i<=n;i++{
		res+=i
	}
	fmt.Println(p.Name,"计算的结果=",res)
}
func (p Person) getSum(n1 int,n2 int) int{
	return n1+n2
}
func main(){
	var p Person=Person{"tom"}
	p.speak()
	p.jisuan()
	p.jisuan2(20)
	res1 := p.getSum(10,20)
	fmt.Println("res=",res1)
	fmt.Println("getSum(10,20)=",p.getSum(10,20)) 
	//这一行说明，计算结果虽然没有传给变量，直接输出，也不会报错

	n1 := 10
	n2 := 20
	res := p.getSum(n1,n2)
	fmt.Println("res=",res)
}