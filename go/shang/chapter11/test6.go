package main

import "fmt"
 
 
type Good struct{
	Name string
	Price float64
}
type Brand struct{
	Name string
	Address string
}
type TV struct{
	Good
	Brand
}
func main(){
	tv := TV{
		Good{
			Name: "电视机",
			Price: 5000.99},
		Brand{"海尔","山东"},
	}
	fmt.Println("tv=",tv)
}