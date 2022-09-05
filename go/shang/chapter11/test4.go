package main

import "fmt"

type Student struct{
	Name string
	Age int
	Score int
}
func (stu *Student) ShowInfo(){
	fmt.Printf("学生名=%v 年龄=%v 成绩=%v\n",stu.Name,stu.Age,stu.Score)
}
func (stu *Student) testing(){
	fmt.Println("学生正在测试")
}
func (stu *Student) SetScore(score int){
	stu.Score=score
}
type Pupil struct{
	Student //匿名结构体
}
type Graduate struct{
	Student //匿名结构体
}
func (p *Pupil) testing(){
	fmt.Println("小学生正在考试中...")
}
func (g *Graduate) testing(){
	fmt.Println("大学生正在考试中")
}
func main(){
	// var pupil Pupil
	// pupil.Student.Name="tom"
	// pupil.Student.Age=8
	// pupil.testing()
	// pupil.Student.SetScore(80)
	// pupil.ShowInfo()

	var graduate Graduate
	graduate.Name="mary"
	graduate.Age=20
	graduate.testing()
	graduate.SetScore(80)
	graduate.ShowInfo()

	graduate.Student.testing()
}