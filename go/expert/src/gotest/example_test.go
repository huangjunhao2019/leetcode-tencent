package gotest_test

import "gotest"

func ExampleSayHello() {
	gotest.SayHello()
	//OutPut: Hello World
}

func ExampleSayGoodbye() {
	gotest.SayGoodbye()
	//OutPut:
	//Hello,
	// goodbye
}

func ExamplePrintNames() {
	gotest.PrintNames()
	//Unordered output:
	//Jim
	//Bob
	//Tom
	//Sue
}
