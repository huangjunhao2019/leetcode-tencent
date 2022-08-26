package main
import "fmt"
func main(){
	var num5=1.2
	fmt.Printf("num的数据类型是%T\n",num5)
	//十进制数形式
	num6 := 5.12
	num7 := .123 //.123等价于0.123
	fmt.Println("num6=",num6,"num7=",num7)

	// 科学计数法形式
	num8 := 5.123e2 //等价于5.123*100
	num9 := 5.123E2 //等价于5.123 *100
	num10 := 5.123e-2 //等价于5.123/100
	num11 := 5.123E-2 //等价于 5.123/100
	fmt.Println("num8=",num8)
	fmt.Println("num9=",num9)
	fmt.Println("num10=",num10)
	fmt.Println("num11=",num11)
}