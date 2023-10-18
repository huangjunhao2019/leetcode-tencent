package main
import "fmt"

func main(){
	orderLen := 5
	order := make([]int,2*orderLen)
	pollOrder := order[:orderLen:orderLen]
	lockOrder := order[orderLen:][:orderLen:orderLen]

	fmt.Println("len(pollOrder)=",len(pollOrder))
	fmt.Println("cap(pollOrder)=",cap(pollOrder))
	fmt.Println("len(lockOrder)=",len(lockOrder))
	fmt.Println("cap(lockOrder)=",cap(lockOrder))
}