package main

type Student struct {
	Name string
	Age  int
}

func StudentRegister(name string, age int) *Student {
	s := new(Student)
	s.Name = name
	s.Age = age
	return s
}
func main() {
	StudentRegister("Jim", 18)
}
