package main

import (
	"fmt"
	"math"
)

type Circle struct{
	radius float64
}
func (c Circle) area() float64{
	return math.Pi*c.radius*c.radius
}
//为了提高效率，通常我们的方法和接头体的指针类型绑定
func (c *Circle)area2()float64{
	c.radius=10
	return 3.14*c.radius*c.radius
}
func main(){
	var c Circle
	c.radius=4
	res := (&c).area2()
	//编译器做了底层优化：(&c).area2()等价于c.area2()
	res2 := c.area2()
	fmt.Println("res=",res,"res2=",res2,"c.area()=",c.area())
	// res := c.area()
	// fmt.Println("面积是=",res)
}