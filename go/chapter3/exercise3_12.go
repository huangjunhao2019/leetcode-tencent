package main
import (
	"os"
	"fmt"
)
func main(){
	if len(os.Args[1:])%2!=0{
		fmt.Fprintf(os.Stderr,"The number of arguments must be pair\n")
		os.Exit(1)
	}
	for i := 1;i<len(os.Args);i+=2{
		if isAnagram(os.Args[i],os.Args[i+1]){
			fmt.Printf("isAnagram( %q,%q) == true\n",os.Args[i],os.Args[i+1])
		}else{
			fmt.Printf("isAnagram( %q,%q) ==false\n",os.Args[i],os.Args[i+1])
		}
	}
}
func isAnagram(a,b string) bool{
	if a==b{
		return false
	}
	ra,rb := []rune(a),[]rune(b)
	if len(ra) != len(rb){
		return false
	}
	ma,mb := make(map[rune]int),make(map[rune]int)
	for i := range ra{
		ma[ra[i]]++
		mb[rb[i]]++
	}
	for i,n := range ma{
		if n!=mb[i]{
			return false
		}
	}
	return true
}