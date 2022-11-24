package main

import (
	"fmt"
	"reflect"
)

func reflectTest(b interface{}){
	//通过反射获取到传入的变量的type，kind，值
	//1. 先获取到reflect.Type
	rType := reflect.TypeOf(b)
	fmt.Println("rType=",rType)
	//2. 获取到reflect.Value
	rVal := reflect.ValueOf(b)
	// n2 := 2+rVal //不能相加，会报错，因为rVal的类型是reflect.Value
	// fmt.Println("n2=",n2)
	n2 := 2+rVal.Int() //将rVal转成了int
	fmt.Println("n2=",n2)
	fmt.Printf("rVal=%v rVal type=%T\n",rVal,rVal) //
	// 下面我们将rVal转成interface{}
	iv := rVal.Interface()
	//将interface{}通过断言转成需要的类型
	num2 := iv.(int)
	fmt.Println("num2=",num2)
}
func reflectTest02(b interface{}){

}
type Student struct{
	Name string
	Age int
}

func main(){
	// 1. 先定义一个int
	var num int = 100
	reflectTest(num)
	// 2. 定义一个Student的实例
	stu := Student{
		Name: "tom",
		Age: 10,
	}
}