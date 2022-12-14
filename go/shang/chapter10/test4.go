package main

import "fmt"

type Point struct{
	x int
	y int
}
type Rect struct{
	leftUp Point
	rightDown Point
}
type Rect2 struct{
	leftUp *Point
	rightDown *Point
}
func main(){
	r1 := Rect{Point{1,2},Point{3,4}}
	//r1有4个整数，在内存中是连续分布的
	fmt.Printf("r1.leftUp.x 地址=%p r1.leftUp.y 地址=%p r1.rightDown.x 地址=%p r1.rightDown.y 地址=%p\n",
	&r1.leftUp.x,&r1.leftUp.y,&r1.rightDown.x,&r1.rightDown.y)

	//r2有两个*Point类型，这两个*Point类型的本身地址也是连续的，但是他们指向的地址不一定是连续的
	r2 := Rect2{&Point{10,20},&Point{30,40}}
	fmt.Printf("r2.leftUp地址=%p  r2.rightDown地址=%p \n", &r2.leftUp,&r2.rightDown,
	 )
	 fmt.Printf("r2.leftUp=%p  r2.rightDown=%p \n", r2.leftUp,r2.rightDown,
	 )
	//他们指向的地址不一定是连续的
}