package main
import(
	"fmt"
	"crypto/sha256"
)
func main(){
	c1 := sha256.Sum256([]byte("x"))
	c2 := sha256.Sum256([]byte("X"))
	fmt.Printf("%x\n%x\n%t\ndiffBits() %d\n",c1,c2,c1==c2,diffBits(&c1,&c2))
}
func diffBits(a,b *[sha256.Size]byte)(n int){
	for i := range a{
		for j := uint(1);j<256;j<<=1{//这里相当于从第0位到第7位的遍历
			if a[i] & byte(j) != b[i] & byte(j){
				n++
			}
		}
	}
	return
}