#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

class Card { 
        Card() { num = 0; }
        Card(int n) : num(n) {}
        void printNum() { std::cout << num << std::endl; }
    private: 
        int num;
};

int main() { 
    std::vector<char> arr(50);
    int num = 0;
    std::for_each(arr.begin(), arr.end(), [&] (char b) {
        b = (char) num + '0'; 
        num++;
        std::cout << b << std::endl; 
    });
    return 1;
}