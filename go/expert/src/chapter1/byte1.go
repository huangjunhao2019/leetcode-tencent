package main

import "fmt"

func main(){
	const (
		bit0,mask0=1<<iota,1<<iota-1
		bit1,mask1
		_,_
		bit3,mask3
	)
	fmt.Printf("bit0=%v, mask0=%v\n",bit0,mask0)
	fmt.Printf("bit1=%v, mask1=%v\n",bit1,mask1)
	fmt.Printf("bit3=%v, mask3=%v\n",bit3,mask3)
}