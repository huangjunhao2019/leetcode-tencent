package main

import(
	"fmt"
	"go_code/factory" //这里引用到包所在文件夹即可
)
func main(){
	// var stu = model.student{
	// 	Name : "tom",
	// 	Score : 78.9,
	// }
	//当student机构体是首字母小写，我们可以通过工厂模式来解决
	stu :=model.NewStudent("tom~",88.8)
	fmt.Println(*stu)
	fmt.Println("stu.Name=",stu.Name,"stu.score=",stu.GetScore())
}