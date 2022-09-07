package main

import(
	"fmt"
	"time"
)
func main(){
	start := time.Now().UnixMilli()
	for i:=2;i<=80000;i++{
		for j:=2;j<i;j++{
			if i%j==0{
				break
			}
		}
	}
	end := time.Now().UnixMilli()
	fmt.Println("普通方法耗时=",end-start)
}