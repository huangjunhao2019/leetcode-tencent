package main
import "fmt"
type Currency int
const(
	USD Currency = iota
	EUR
	GBP
	RMB
)
func main(){
	symbol := [...]string{USD:"u",EUR:"e",GBP:"g",RMB:"r"}
	fmt.Println(RMB,symbol[RMB])
	r := [...]int{10:-1}
	fmt.Println(len(r))
	a := [2]int{1,2}
	b := [...]int{1,2}
	c := [2]int{1,3}
	fmt.Println(a==b,a==c,b==c)
	
}