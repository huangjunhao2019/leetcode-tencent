package main

import "fmt"
type Visitor struct{
	Name string
	Age int
}
func (v *Visitor)ticketPrice() float64 {
	if v.Age>18{
		return 20
	}
	return 0
}
func main(){
	var v1 = Visitor{"李红",20}
	var v2 =Visitor{"张强",15}
	fmt.Printf("%v的票价是%v\n",v1.Name,v1.ticketPrice())
	fmt.Printf("%v的票价是%v\n",v2.Name,v2.ticketPrice())
}