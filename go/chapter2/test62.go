package main

import "fmt"
func main(){
	p := newInt()
	q := newInt2()
	fmt.Println(*p==*q,p==q)
}
func newInt() *int{
	return new(int)
}
func newInt2() *int{
	var dummy int
	return &dummy
}