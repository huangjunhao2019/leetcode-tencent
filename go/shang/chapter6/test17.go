package main

import (
	"fmt"
	"time"
)

func main(){
	now := time.Now()
	fmt.Println("unix=",now.Unix())
	fmt.Println("unixnano=",now.UnixNano())
}