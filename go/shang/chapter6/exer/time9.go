package main

import(
	"time"
	"fmt"
)
func main(){
	t := time.Date(1990,1,1,0,0,0,0,time.Local)
	d := time.Since(t)
	day := 0
	if int(d.Hours())%24==0{
		day = int(d.Hours())/24
	} else{
		day=int(d.Hours())/24+1
	}
	if day%5<3{
		fmt.Println("打鱼")
	} else{
		fmt.Println("晒网")
	}
}