package main
import(
	"fmt"
	"os"
)
func main(){
	for temp,arg := range os.Args{
		fmt.Println(temp)
		fmt.Println(arg)
	}
}