package main

import "fmt"

func main(){
	var grade [3][5]float64
	for i := 0;i<len(grade);i++{
		for j :=0;j<len(grade[i]);j++{
			fmt.Printf("请输入%v班第%v个学生的成绩\t",i+1,j+1)
			fmt.Scanln(&grade[i][j])
		}
	}
	var avgClass [3]float64
	var sumAll float64 =0 
	for index,val := range grade{
		var sumClass float64=0
		for _,score := range val{
			sumClass+=float64(score)
			sumAll+=float64(score)
		}
		avgClass[index]=sumClass/float64(len(val))
	}
	averageAll := sumAll/float64(15)
	for i:=0 ;i<len(avgClass);i++{
		fmt.Printf("%v班的平均分是%v\n",i,avgClass[i])
	}
	fmt.Println("所有人的平均分=",averageAll)
}