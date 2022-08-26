package main

import (
	"bufio"
	"bytes"
	"fmt"
)
type ByteCounter int

func (c *ByteCounter) Write(p []byte)(int,error){
	*c+=ByteCounter(len(p))
	return len(p),nil
}
type WordCounter int
func (w *WordCounter) Write(p []byte)(int,error){
	scanner := bufio.NewScanner(bytes.NewReader(p))
	scanner.Split(bufio.ScanWords)

	n := 0
	for scanner.Scan(){
		n++
	}
	*w += WordCounter(n)
	return n,nil
}

type LineCounter int
func (l *LineCounter) Write(p []byte)(int,error){
	scanner := bufio.NewScanner(bytes.NewReader(p))
	scanner.Split(bufio.ScanLines)

	n := 0
	for scanner.Scan(){
		n++
	}
	*l += LineCounter(n)
	return n,nil
}
func main(){
	var c ByteCounter
	c.Write([]byte("hello"))
	fmt.Println(c)

	c=0
	var name="Dolly"
	fmt.Fprintf(&c,"hello, %s",name)
	fmt.Println(c)

	var w WordCounter
	w.Write([]byte("hello hillo hollo hullo"))
	fmt.Println(w)

	w = 0
	name = "1 2 3 4 1969 778"
	fmt.Fprintf(&w,"hello, &s",name)
	fmt.Println(w)

	var l LineCounter
	l.Write([]byte("hello\n hillo\n hollo\n hullo"))
	fmt.Println(l)

	l=0
	name="1\n 2\n 3\n 4\n 1969\n 778"
	fmt.Fprintf(&l,"hello\n %s",name)
	fmt.Println(l)
}