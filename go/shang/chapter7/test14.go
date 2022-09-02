package main

import "fmt"

func main(){ 
	str := "hello@atguigu"
	arr := []byte(str)
	arr[0]='z'
	str1 := string(arr)
	fmt.Println("str1=",str1)
	//细节：我们转成[]byte后，可以处理英文和数字，但是不能处理中文
	//原因：[]byte按字节来处理，而一个汉字，是三个字节，因此会出现乱码
	arr2 := []rune(str)
	arr2[0] = '北'
	str2 := string(arr2)
	fmt.Println("str2=",str2)
}