package main
import(
	"fmt"
	"math"
)
const(
	width,height=600,320
	cells=100
	xyrange=30.0
	xyscale=width/2/xyrange
	zscale=height*0.4
	angle=math.Pi/6
)
var sin30,cos30=math.Sin(angle),math.Cos(angle)
func main(){
	fmt.Printf("width='%d' height='%d'",width,height)
	for i := 0;i<cells;i++{
		for j := 0;j<cells;j++{
			corner(i+1,j)
			corner(i,j)
			corner(i,j+1)
			corner(i+1,j+1)
			//fmt.Printf("<polygon points='%g, %g, %g")
		}
	}
	fmt.Println("</svg>")
}
func corner(i,j int) (float64,float64){
	x := xyrange*(float64(i)/cells-0.5)
	y := xyrange*(float64(j)/cells-0.5)

	z := f(x,y)

	sx := width/2+(x-y)*cos30*xyscale
	sy := height/2+(x+y)*sin30*xyscale-z*zscale
	return sx,sy
}
func f(x,y float64) float64{
	r := math.Hypot(x,y)
	return math.Sin(r)/r
}