package main
import(
	"fmt"
	"flag"
	"crypto/sha256"
	"crypto/sha512"
)
var s384 = flag.Bool("384",false,"print sha384")
var s512 = flag.Bool("512",false,"print sha512")
func main(){
	flag.Parse()
	for _,arg := range flag.Args(){
		fmt.Printf("%q\nsha256==> %x\n",arg,sha256.Sum256([]byte(arg)))
		if *s384{
			fmt.Printf("sha384==> %x\n",sha512.Sum384([]byte(arg)))
		}
		if *s512{
			fmt.Printf("sha512==> %x\n",sha512.Sum512([]byte(arg)))
		}
	}
}