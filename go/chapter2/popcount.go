package main
import (
	"fmt"
)
var pc [256] byte
func main(){
	for i:= range pc{
		pc[i]=pc[i/2]+byte(i&1)
	}
	for i:=range pc{
		fmt.Printf("%d=%d\n",i,pc[i])
	}
}