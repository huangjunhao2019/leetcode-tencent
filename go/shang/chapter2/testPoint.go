package main
import "fmt"
type Point struct{
	x,y int
}
func main(){
	p := Point{1,2}
	fmt.Println(p.x)
}