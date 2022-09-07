package main

import "fmt"

type Cat struct{
	Name string
	Age int
}
func main(){
	var allChan chan interface{}
	allChan=make(chan interface{},10)

	cat1 := Cat{Name:"tom",Age:18}
	cat2 := Cat{Name:"tom~",Age:180}
	allChan <- cat1
	allChan <- cat2
	allChan <- 10
	allChan <- "jack"

	cat11 := <- allChan

	// fmt.Println(cat11.Name) //报错，因为类型是空接口，需要类型断言
	fmt.Println((cat11.(Cat)).Name) //使用类型断言即可

}