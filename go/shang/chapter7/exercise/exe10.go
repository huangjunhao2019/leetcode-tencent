package main

import "fmt"

func lessGreatAve(arr [8]int) (int,int){
	sum := 0.0
	for _,val := range arr{
		sum+=float64(val)
	}
	ave := sum/float64(len(arr))
	less := 0
	great := 0
	for _,val := range arr{
		if float64(val)<ave{
			less++
		}
		if float64(val)>ave{
			great++
		}
	}
	return less,great
}
func main(){
	var arr [8]int=[8]int{8,9,7,6,1,2,3,4}
	lessAve,greatAve := lessGreatAve(arr)
	fmt.Printf("有%v个数大于平均值，有%v个\n",lessAve,greatAve)
}