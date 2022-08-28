package main
import "fmt"
func test() bool{
	fmt.Println("test...")
	return true
}
func main(){
	var i int = 10
	if i>9 || test() {//后面的test不会执行
		//因为第一个条件已经为真了，第二个条件不执行了
		fmt.Println("hello...")
	}
}