package main

import(
	"fmt"
	"go_code/factory"
)

func main(){
	p := model.NewPerson("tom")
	p.SetAge(18)
	p.SetSal(5000)
	fmt.Println(*p)
	fmt.Println(p.Name,"age=",p.GetAge(),"sla=",p.GetSal())
}