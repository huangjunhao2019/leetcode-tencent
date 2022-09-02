package main

import "fmt"
type A struct{
	Num int
}
func (a A) test(){ //此处对Num修改并不影响原来的a，原来的a的Num还是0
	a.Num=10
	fmt.Println("test() ",a.Num)
}
func main(){
	var a A
	a.test()
	fmt.Println("a.Num=",a.Num)
}