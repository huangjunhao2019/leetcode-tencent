package main

import "fmt"

func main(){
	var totalSum float64 = 0.0
	for j := 1; j<=3 ;j++{
		sum := 0.0
		for i := 1;i<=5;i++{
			var score float64
			fmt.Printf("请输入第%v班第%v个学生成绩\n",j,i)
			fmt.Scanln(&score)
			sum += score
		}
		totalSum+=sum
		fmt.Printf("第%v个班级平均分是%v\n",j,sum/5)
	}
	fmt.Printf("各个班级的总成绩是%v, 各个班级平均分是%v\n",totalSum,totalSum/(5*3))
}