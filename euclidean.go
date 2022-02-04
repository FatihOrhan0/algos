// a quick implementation of gcd finder using the Euclidean

package main

import "fmt"

func min(a, b int) int { 
	if (a < b) { return a
	} else { return b }
}

func max(a, b int) int { 
	if (a > b) { return a
	} else { return b }
}


func findGCD(a int, b int) int{ 
	if (a % b == 0 || b % a == 0) { 
		return min(a, b)
	}
	if (a > b) {
		mul := a / b
		remainder := a - mul * b
		return findGCD(remainder, b)
	} else { 
		mul := b / a
		remainder := b - mul * a 
		return findGCD(remainder, a)
	}
}

func main() {
	fmt.Println(findGCD(320, 226))
}
