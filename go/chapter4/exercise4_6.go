package main
import(
	"fmt"
	"unicode"
	"unicode/utf8"
)
func rmSpace(s []byte)[]byte{
	inspace ,j := false,0
	for i,r := range string(s){
		if unicode.IsSpace(r){
			inspace = true
			continue
		}else if inspace{
			inspace = false
			s[j]=' '
			j++
		}
		w := utf8.RuneLen(r)
		copy(s[j:],s[i:i+w])
		j += w
	}
	return s[:j]
}
func main(){
	a := []byte("  a \t \v spa  test \n")
	fmt.Printf("%q\n",string(a))
	a=rmSpace(a)
	fmt.Printf("%q\n",string(a))
}