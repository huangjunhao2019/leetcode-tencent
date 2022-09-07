package main

import(
	"fmt"
	"sync"
	"time"
)

var myMap = make(map[int]int,10)
var lock sync.Mutex
func test(n int){
	res := 1
	for i := 1;i<=n;i++{
		res+=i
	}
	lock.Lock()
	myMap[n]=res
	lock.Unlock()
}
func main(){
	for i:=1;i<=200;i++{
		go test(i)
	}
	time.Sleep(time.Second*10)
	lock.Lock()
	for key,val := range myMap{
		fmt.Printf("map[%v]=%v\n",key,val)
	}
	lock.Unlock()
}