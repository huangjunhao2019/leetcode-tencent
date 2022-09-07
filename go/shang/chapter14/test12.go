package main

import(
	"fmt"
	"encoding/json"
)

type Monster struct{
	Name string `json:"monster_name"`
	Age int `json:"monster_age"`
	Birthday string
	Sal float64
	Skill string
}
func testMap(){
	var a map[string]interface{}
	//使用map前需要make
	a = make(map[string]interface{})
	a["name"]="红孩儿"
	a["age"]=30
	a["skill"]="三味真火"
	data,err := json.Marshal(a)
	if err!=nil{
		fmt.Printf("序列化错误 err=%v\n",err)
	}
	fmt.Printf("a map 序列化后=%v\n",string(data))
}
func testStruct(){
	monster := Monster{
		Name : "牛魔王", 
		Age : 500,
		Birthday: "2011-11-11",
		Sal: 8000.0,
		Skill: "牛魔拳",
	}
	data,err := json.Marshal(&monster)
	if err != nil{
		fmt.Printf("序列化错误 err=%v\n",err)
	}
	//输出序列化后的结果
	fmt.Printf("monster 序列化后=%v\n",string(data))
}
func testSlice(){
	var slice []map[string]interface{}
	var m1 map[string]interface{}
	m1 = make(map[string]interface{})
	m1["name"]="jack"
	m1["age"]="7"
	m1["address"]="北京"
	slice=append(slice, m1)

	var m2 map[string]interface{}
	m2 = make(map[string]interface{})
	m2["name"]="tom"
	m2["age"]="20"
	m2["address"]="墨西哥"
	slice=append(slice,m2)
	data,err := json.Marshal(&slice)
	if err != nil{
		fmt.Printf("序列化错误 err=%v\n",err)
	}
	//输出序列化后的结果
	fmt.Printf("slice 序列化后=%v\n",string(data))

}
//对基本数据类型序列化
func testFloat64(){
	var num1 float64 = 2345.67
	data,err := json.Marshal(&num1)
	if err != nil{
		fmt.Printf("序列化错误 err=%v\n",err)
	}
	//输出序列化后的结果
	fmt.Printf("float64 序列化后=%v\n",string(data))
}
func main(){
	//演示将结构体、map，切片进行序列化
	 testStruct()
	 
}