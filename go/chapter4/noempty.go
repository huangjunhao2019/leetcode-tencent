package main
import "fmt"
func noempty(strings []string) []string{
	i := 0
	for _,s := range strings{
		if s!=""{
			strings[i]=s
			i++
		}
	}
	return strings[:i]
}
func main(){
	data := []string{"one","","three"}
	fmt.Printf("%q\n",noempty(data))
	fmt.Printf("%q\n",data)
}