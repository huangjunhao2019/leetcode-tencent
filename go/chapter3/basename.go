package main

import (
	"fmt"
	"strings"
)
func basename1(s string) string{
	for i := len(s)-1;i>=0;i--{
		if s[i]=='/'{
			s=s[i+1:]
			break
		}
	}
	for i := len(s)-1;i>=0;i--{
		if s[i]=='.'{
			s=s[:i]
			break
		}
	}
	return s
}
func basename2(s string) string{
	slash := strings.LastIndex(s,"/")
	s=s[slash+1:]
	if dot := strings.LastIndex(s,"."); dot>=0{
		s=s[:dot]
	}
	return s
}
func main(){
	var s1 string="a/b/c.go"
	var s2 string="c.d.go"
	var s3 string="abc"
	fmt.Println(s1)
	fmt.Println(basename1(s1))
	fmt.Println(basename2(s1))

	fmt.Println(s2)
	fmt.Println(basename1(s2))
	fmt.Println(basename2(s2))

	fmt.Println(s3)
	fmt.Println(basename1(s3))
	fmt.Println(basename2(s3))
}