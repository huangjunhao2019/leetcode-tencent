package main

import "fmt"

func main(){
	//1.打印一个矩形
	// for i := 1;i<=3;i++{
	// 	for j := 1;j<=3;j++{
	// 		fmt.Print("*")
	// 	}
	// 	fmt.Println()
	// }
	//2.打印半个金字塔
	/*
		*
		**
		***
	*/
	//  for i:=1;i<=3;i++{
	// 	for j:=1 ;j<=i;j++{
	// 		fmt.Print("*")
	// 	}
	// 	fmt.Println()
	//  }
	//3. 打印整个金字塔
	/*
		*    //空格：2 规律：总层数-当前层数
       ***	 //空格：1
	  ***** // 2*层数-1
	*/
	// var totalLevel =3
	// for i := 1; i<=totalLevel;i++{
	// 	for k := 1;k<=totalLevel-i;k++{
	// 		fmt.Print(" ")
	// 	}
	// 	for j := 1;j<=2*i-1;j++{
	// 		fmt.Print("*")
	// 	}
	// 	fmt.Println()
	// }
	//5. 打印空心金字塔
	/*
			*
		   * *
		  *****
	*/
	var totalLevel int = 12
	for i:= 1;i<=totalLevel;i++{
		for k:=1 ;k<=totalLevel-i;k++{
			fmt.Print(" ")
		}
		for j := 1; j<=2*i-1;j++{
			if j == 1 || j == 2*i-1 || i == totalLevel{
				fmt.Print("*")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}