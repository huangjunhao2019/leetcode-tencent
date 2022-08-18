package main
import(
	"fmt"
	"strconv"
)
func main(){
	x := 123
	y := fmt.Sprintf("%d",x)
	fmt.Println(y,strconv.Itoa(x))

	fmt.Println(strconv.FormatInt(int64(x),2))
	sb := fmt.Sprintf("x=%b",x)
	so := fmt.Sprintf("x=%o",x)
	sx := fmt.Sprintf("x=%x",x)
	fmt.Printf("%d=%s\n",x,sb)
	fmt.Printf("%d=%s\n",x,so)
	fmt.Printf("%d=%s\n",x,sx)
}