package main

import "fmt"

func countDay(year int,month int) int{
	var isLeap bool = false
	if year % 4==0 && year%100!=0 || year%400==0{
		isLeap=true
	}
	switch month{
	case 1,3,5,7,8,10,12:
		return 31
	case 2:
		if isLeap{
			return 29
		} else {
			return 28
		}
	case 4,6,9,11:
		return 30
	default:
		return -1
	}
}
func main(){
	var year int
	var month int
	for {
		fmt.Println("请输入年")
		fmt.Scanln(&year)
		fmt.Println("请输入月份")
		fmt.Scanln(&month)
		if month<1 || month>12{
			fmt.Println("输入错误，请重新输入")
		} else{
			fmt.Printf("%v年%v月共有%v天\n",year,month,countDay(year,month))
		}
	}
}