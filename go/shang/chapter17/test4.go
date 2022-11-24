package main

import(
	"reflect"
	"fmt"
)
func reflect01(b interface{}){
	rVal := reflect.ValueOf(b)
	// fmt.Printf("rval kind=%v\n",rVal.Kind())
	rVal.Elem().SetInt(20) //Elem()相当于*
}
func main(){
	var num int = 10
	reflect01(&num)
	fmt.Println("num=",num)
}