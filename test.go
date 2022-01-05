package main

import (
	"fmt"
)

func printer() {
	var Mystring string = "hello"
	fmt.Println(Mystring)
}

func main() {
	var Myint int = 5
	fmt.Println(Myint)
	for i := 0; i < 5; i++ {
		fmt.Println(i, " ")
	}
	fmt.Print()
	printer()
}
