package main

import "fmt"

func isPrime(n int) bool{
	if n==1 || n==0 {
		return false
	}
	for i :=2 ;i<n;i++{
		if n%i==0{
			return false
		}
	}
	return true
}
func main(){
	res :=0
	count :=0
	for i:=1;i<=100;i++{
		if isPrime(i){
			fmt.Printf("%v\t",i)
			count++
			res+=i
			if count % 5==0 {
				fmt.Println()
			}
		}
	}
	fmt.Println("res=",res)
}