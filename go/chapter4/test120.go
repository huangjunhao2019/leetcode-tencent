package main
import "fmt"
func main(){
	var a [3]int
	fmt.Println(a[0])
	fmt.Println(a[len(a)-1])
	fmt.Println("print1")
	for i,v := range a{
		fmt.Printf("%d %d\n",i,v)
	}
	fmt.Println("print2")
	for _,v := range a{
		fmt.Printf("%d\n",v)
	}
	fmt.Println("print3")
	for i := 0;i<len(a);i++{
		fmt.Println(a[i])
	}
	fmt.Println("print4")
	var q [3]int=[3]int{1,2,3}
	var r [3]int=[3]int{1,2}
	for i,v := range q{
		fmt.Printf("%d %d\n",i,v)
	}
	for i,v := range r{
		fmt.Printf("%d %d\n",i,v)
	}
	fmt.Printf("%T\n",q)
	fmt.Printf("%T\n",r)
}