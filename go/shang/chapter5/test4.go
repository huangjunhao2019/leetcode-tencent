package main

import "fmt"

func main(){
	var height int32
	var money float32
	var handsome bool
	
	fmt.Println("请输入身高")
	fmt.Scanln(&height)

	fmt.Println("请输入财富（千万）")
	fmt.Scanln(&money)

	fmt.Println("请输入是否帅（true/false）")
	fmt.Scanln(&handsome)

	if height > 180 && money > 1.0 && handsome{
		fmt.Println("我一定要嫁给他！")
	} else if height>180 || money>1.0 || handsome {
		fmt.Println("嫁吧，比上不足，比下有余")
	} else{
		fmt.Println("不嫁...")
	}
}