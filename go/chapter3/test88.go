package main
import "fmt"
func main(){
	num := 0666
	fmt.Printf("%d %[1]o %#[1]o\n",num)
	num2 := int64(0xdeadbeef)
	fmt.Printf("%d %[1]x %#[1]x %#[1]X\n",num2)

	ascii := 'a'
	unicode := '国'
	newline := '\n'
	fmt.Printf("%d %[1]c %[1]q\n",ascii)
	fmt.Printf("%d %[1]c %[1]q\n",unicode)
	fmt.Printf("%d %[1]q\n",newline)
}