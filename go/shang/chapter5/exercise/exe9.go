package main

import "fmt"

func main(){
	var grade int
	fmt.Scanln(&grade)
	if grade == 100{
		fmt.Println("BMW")
	} else if (grade>80 && grade<=99){
		fmt.Println("iphone 7 plus")
	} else if (grade>=60 && grade<=80){
		fmt.Println("ipad")
	} else {
		fmt.Println("nothing")
	}
}