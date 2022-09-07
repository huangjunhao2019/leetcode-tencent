package main

import (
	"flag"
	"fmt"
)

func main(){
	//定义几个变量，用于接收命令行参数
	var user string
	var pwd string
	var host string
	var port int
	//&user就是接收用户命令行输入中的 -u 后面的参数值
	//"u",就是-u指定参数
	//""，默认值
	flag.StringVar(&user,"u","","用户名默认为空")
	flag.StringVar(&pwd,"pwd","","密码默认为空")
	flag.StringVar(&host ,"h","localhost","主机名默认为localhost")
	flag.IntVar(&port,"p",3306,"端口号默认为3306")

	flag.Parse()
	fmt.Printf("user=%v pwd=%v host=%v port=%v\n",user,pwd,host,port)
}