package main
import "fmt"
var pc [256]byte
func init(){
	for i:=range pc{
		pc[i]=pc[i/2]+byte(i&1)
	}
}
func popCount1(x int) int{
	return int(pc[byte(x>>(0*8))]+
	pc[byte(x>>(1*8))]+
	pc[byte(x>>(2*8))]+
	pc[byte(x>>(3*8))]+
	pc[byte(x>>(4*8))]+
	pc[byte(x>>(5*8))]+
	pc[byte(x>>(6*8))]+
	pc[byte(x>>(7*8))])
}
func popCount2(x int) int{
	n:=0
	for i:=0;i<8;i++{
		n+=int(pc[byte(x>>(i*8))])
	}
	return n
}
func popCount3(x int) int{
	n := 0
	for i:=0;i<64;i++{
		if x&1 != 0{
			n++
		}
		x=x>>1
	}
	return n
}
func popCount4(x int) int{
	n:=0
	for x!=0{
		x=x&(x-1)
		n++
	}
	return n
}
func main(){
	x:=255
	fmt.Println(popCount1(x))
	fmt.Println(popCount2(x))
	fmt.Println(popCount3(x))
	fmt.Println(popCount4(x))
}