package main

import (
	"errors"
	"fmt"
)

//函数去读取配置文件init.conf的信息
//如果文件名传入不正确，我们就返回一个自定义的错误
func readConf(name string) (err error){
	if  name == "init.conf"{
		return nil
	} else{
		return errors.New("读取文件错误")
	}
}
func test02(){
	err := readConf("init.conff")
	if err != nil{
		//如果读取文件发生错误，则输出错误，终止执行
		panic(err)
	}
	fmt.Println("test02()继续执行")
}
func main(){
	 test02()
}