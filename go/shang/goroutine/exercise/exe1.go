package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Person struct{
	Name string
	Age int
	Address string
}

func main(){
	var perChan chan Person
	perChan = make(chan Person,10)
	rand.Seed(time.Now().UnixNano())
	for i:=0;i<10;i++{
		newPerson := Person{fmt.Sprintf("tom%v",i),rand.Intn(100)+1,fmt.Sprintf("中国%v",rand.Intn(100)+1)}
		perChan <- newPerson
	}
	for len(perChan)!=0{
		fmt.Println(<- perChan)
	}
}