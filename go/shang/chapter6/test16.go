package main

import (
	"fmt"
	"time"
)

func main(){
	//查看日期和时间相关函数使用
	//1.获取当前时间
	now := time.Now()
	fmt.Printf("now=%v now type= %T\n",now,now)
	//2. 通过now可以获取到年月日，时分秒
	fmt.Printf("年=%v\n",now.Year())
	fmt.Printf("月=%v\n",int(now.Month()))
	fmt.Printf("日=%v\n",now.Day())
	fmt.Printf("时=%v\n",now.Hour())
	fmt.Printf("分=%v\n",now.Minute())
	fmt.Printf("秒=%v\n",now.Second())

	// 3.格式化日期时间
	//格式化时间第一种方式
	fmt.Printf("当前年月日 %02d-%02d-%02d %02d:%02d:%02d\n",now.Year(),now.Month(),now.Day(),//0代表不足两位补0
	now.Hour(),now.Minute(),now.Second(),
	)	
	dateStr := fmt.Sprintf("当前年月日 %d-%d-%d %d:%d:%d\n",now.Year(),now.Month(),now.Day(),
	now.Hour(),now.Minute(),now.Second(),
	)
	fmt.Println(dateStr)	
	//格式化第二种方式
	fmt.Printf(now.Format("2006/01/02 15:04:05")) //时间必须得固定的，必须得是2006年这个时间，不能改成其他
}