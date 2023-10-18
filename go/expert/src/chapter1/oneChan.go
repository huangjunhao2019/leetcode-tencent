package main

func readChan(chanName <-chan int) {
	<-chanName
}
func writeChan(chanName chan<- int) {
	chanName <- 1
}
func main() {
	var myChan = make(chan int, 10)
	writeChan(myChan)
	readChan(myChan)
}
