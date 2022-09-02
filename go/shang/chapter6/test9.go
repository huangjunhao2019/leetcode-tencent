package main
import (
	"fmt"
	"go_code/model"
)
var age = test()
func test() int{
	fmt.Println("test()")
	return 90
}
func init(){
	fmt.Println("init()...")
}
func main(){
	fmt.Println("main()...age ",age)
	fmt.Println("Age=",model.Age,"Name=",model.Age)
}