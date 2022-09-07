package main

import (
	"encoding/json"
	"fmt"
)

type Monster struct{
	Name string 
	Age int
	Birthday string
	Sal float64
	Skill string
}
//演示将json反序列化为struct
func unmarshalStruct(){
	str := "{\"Age\":30,\"Name\":\"红孩儿\",\"Skill\":\"三味真火\"}"
	var monster Monster
	err := json.Unmarshal([]byte(str),&monster)
	if err != nil{
		fmt.Printf("unmarshal err=%v\n",err)
	}
	fmt.Println("反序列化后 monster=",monster)
}
//演示将json反序列化为map
func unmarshalMap(){
	str := "{\"address\":\"北京\","+
	"\"age\":30}"
	var a map[string]interface{} //此处不需要make，因为已经在unmarshal
	//包含make操作了
	err := json.Unmarshal([]byte(str),&a)
	if err != nil{
		fmt.Printf("unmarshal err=%v\n",err)
	}
	fmt.Printf("反序列化后 a=%v\n",a)

}
 
func main(){
	unmarshalStruct()
	unmarshalMap()
}