package main

import "fmt"

func main(){
	//1.打印实心菱形
	/*
		*	// 空格2，*：1
	   ***	//空格1， *：3
	  ***** //空格0：*：5

	*/
	// 2. 打印空心菱形
	/*
		*		// 空格2，*：1
	   *  *		//空格1，*：2
	  *    *	//空格0
	   *  *		//空格1
	    *		//空格2

	*/
	var totalLevel int = 5
	for i:=1;i<=totalLevel;i++{
		for k := 1;k<=totalLevel-i;k++{
			fmt.Print(" ")
		}
		for j := 1;j<=2*i-1;j++{
			if j == 1 || j == 2*i-1{
				fmt.Print("*")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
	//打印倒三角形
	/*
		***** 空格0 *：5
		 ***  空格1 *：3
		  *   空格2 *：1
	*/
	for i :=2;i<=totalLevel;i++{
		for k := 1;k<=i-1;k++{
			fmt.Print(" ")
		}
		for j := 1;j<=2*totalLevel-2*i+1;j++{
			if j==1 || j==2*totalLevel-2*i+1 {
				fmt.Print("*")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}