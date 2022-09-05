package main

import "fmt"
//小学生
type Pupil struct{
	Name string
	Age int
	Score int
}
func (p *Pupil) showInfo(){
	fmt.Printf("学生名字=%v 年龄=%v 成绩=%v\n",p.Name,p.Age,p.Score)
}
func (p *Pupil) SetScore(score int){
	p.Score=score
}
func (p *Pupil) testing(){
	fmt.Println("小学生正在考试中...")
}
//大学生，研究生？全部重写？代码冗余

func main(){
	var pupil = &Pupil{
		Name : "tom",
		Age : 10,
	}
	pupil.testing()
	pupil.SetScore(90)
	pupil.showInfo()
}