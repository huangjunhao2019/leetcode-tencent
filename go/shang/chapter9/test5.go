package main

import (
	"fmt"
	"sort"
)

func main(){
	//map排序
	map1 := make(map[int]int)
	map1[10]=100
	map1[2]=13
	map1[4]=56
	map1[8]=90
	fmt.Println(map1)
	//如果按照map的key的顺序进行排序输出
	//1. 先将map的key放入切片中
	//2. 对切片进行排序
	//3. 遍历切片，然后按照key来输出map的值
	var keys []int
	for k,_ := range map1{
		keys=append(keys,k)
	}
	//排序
	sort.Ints(keys)
	fmt.Println(keys)

	for _,val := range keys{
		fmt.Printf("map[%v]=%v\n",val,map1[val])
	}
}