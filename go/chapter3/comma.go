package main

import (
	"bytes"
	"fmt"
)
func comma(s string) string{
	n := len(s)
	if n<=3{
		return s
	}
	return comma(s[:n-3])+","+s[n-3:]
}
func comma2(s string) string{
	var buf bytes.Buffer
	for i:=0;i<len(s);i++{
		if i!=0 && i!=len(s)-1 && i%3==0{
			buf.WriteString(",")
		}
		fmt.Fprintf(&buf,"%c",s[i])
	}
	return buf.String()
}
func comma3(s string) string{
	var buf bytes.Buffer
	for i:=0;i<len(s);i+=3{
		if i!=0{
			buf.WriteString(",")
		}
		fmt.Fprintf(&buf,"%s",s[i:i+3])
	}
	return buf.String()
}
func main(){
	fmt.Println(comma3("123456"))
}