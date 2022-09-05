package main

import(
	"fmt"
	"io/ioutil"
)

func main(){
	//使用iotuil.ReadFile一次性将文件读取到位
	file := "./twoCity.txt"
	content,err := ioutil.ReadFile(file)
	if err != nil{
		fmt.Printf("read file err=%v\n",err)
	}
	//我们没有显式Open文件，因此也不需要显式Close
	//文件的Open和Close操作都被包含在ioutil.ReadFile中了
	fmt.Printf("%v\n",content)
	fmt.Printf("%v\n",string(content))
}