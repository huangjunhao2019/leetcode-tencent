package main

import (
	"fmt"
	"os"
)

func main(){
	fmt.Printf("命令行的参数有%v个，os.Args的类型为%T\n",len(os.Args),os.Args)
	//遍历os.Args切片，就可以得到所有的命令行输入参数值
	for index,val := range os.Args{
		fmt.Printf("args[%v]=%v\n",index,val)
	}
}