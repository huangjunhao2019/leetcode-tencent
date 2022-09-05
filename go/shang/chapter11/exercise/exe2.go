package main

import (
	"fmt"
	"math/rand"
	"sort"
)

//1. 声明Hero结构体
type Hero struct{
	Name string
	Age int
}
//2. 声明一个Hero结构体切片类型
type HeroSlice []Hero
//3. 实现Interface
func (hs HeroSlice) Len() int{
	return len(hs)
}
func (hs HeroSlice) Less(i int,j int) bool{
	return hs[i].Age<hs[j].Age
}
func (hs HeroSlice) Swap(i int,j int){
	temp := hs[i]
	hs[i]=hs[j]
	hs[j]=temp
}
func main(){
	var heroes HeroSlice
	for i := 0;i<10;i++{
		hero := Hero{
			Name: fmt.Sprintf("英雄%d",rand.Intn(100)+1),
			Age : rand.Intn(100)+1,
		}
		heroes = append(heroes,hero)
	}
	//看看排序前的顺序
	fmt.Println("排序前")
	for _,v := range heroes{
		fmt.Println(v)
	}
	sort.Sort(heroes)
	fmt.Println("排序后")
	for _,v := range heroes{
		fmt.Println(v)
	}
}