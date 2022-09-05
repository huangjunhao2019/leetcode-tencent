package  main

import "fmt"

//编写一个函数，可以判断输入的参数是什么类型
type Student struct{

}
func TypeJudge(items... interface{}){
	for index, x := range items{
		switch x.(type){
		case bool:
			fmt.Printf("第%v个参数是bool类型,值是%v\n",index,x)
		case float32:
			fmt.Printf("第%v个参数是float32类型,值是%v\n",index,x)
		case float64:
			fmt.Printf("第%v个参数是float64类型,值是%v\n",index,x)
		case int,int32,int64:
			fmt.Printf("第%v个参数是整数类型,值是%v\n",index,x)
		case string:
			fmt.Printf("第%v个参数是string类型,值是%v\n",index,x)
		case Student:
			fmt.Printf("第%v个参数是Student类型,值是%v\n",index,x)
		case *Student:
			fmt.Printf("第%v个参数是*Student类型,值是%v\n",index,x)
		default:
			fmt.Printf("第%v个参数是不确定类型,值是%v\n",index,x)
		}
	}
}
func main(){
	var n1 float32 = 1.1
	var n2 float64 = 2.3
	var n3 int = 30
	var name string = "tom"
	var stu1 Student
	var stu2 *Student
	address := "北京"
	n4 := 300
	TypeJudge(n1,n2,n3,name,address,n4,stu1,stu2)
}