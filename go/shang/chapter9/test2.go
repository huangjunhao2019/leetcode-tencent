package main

import "fmt"

func main(){
	//第一种使用方式
	var a map[string]string
	a = make(map[string]string,10)
	a["no1"]="宋江"
	a["no2"]="吴用"
	a["no3"]="武松"
	fmt.Println(a)
	//第二种使用方式
	cities := make(map[string]string)
	cities["no1"] = "北京"
	cities["no2"] = "天津"
	cities["no3"] = "上海"
	fmt.Println(cities)
	//第三种使用方式
	heroes := map[string]string{
		"hero1" : "songjiang",
		"hero2" : "lujunyi",
	}
	fmt.Println(heroes)
}