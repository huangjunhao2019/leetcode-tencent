package main
import "fmt"
func main(){
	for i:=0;i<10;i++{
		var v=f()
		fmt.Println(v)
	}
	temp := 1
	incr(&temp)
	fmt.Println(incr(&temp))
}
func incr(p *int) int{
	(*p)++
	return *p
}
func f() *int{
	v := 1
	return &v
}