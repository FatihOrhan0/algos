//This is for comparison of the runtime of golang and c++

#include <iostream>

int min(int a, int b) { 
    if (a < b) return b;
    else return a;
}

int findGCD(int a, int b) { 
	if (a % b == 0 || b % a == 0) { 
		return min(a, b);
	}
	if (a > b) {
		return findGCD(a - (a / b) * b, b);
	} else { 
		return findGCD(b - (b / a) * a , a);
	}
}


int main() { 
    std::cout << findGCD(320, 226);
}