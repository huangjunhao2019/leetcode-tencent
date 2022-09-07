package main

import (
	"fmt"
	"runtime"
)
func main(){
	cpuNum := runtime.NumCPU()
	fmt.Println("cpuNum=",cpuNum)
	runtime.GOMAXPROCS(cpuNum)//设置需要的CPU数量
	 
}