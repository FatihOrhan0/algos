#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <functional>
#include <iterator>


int main() { 
    std::random_device d;
    std::default_random_engine generator(d());
    std::uniform_int_distribution<int> distr(0, 1000);

    for (int i = 0; i < 10; i++) 
        std::cout << distr(generator) << std::endl;
    std::cout << d() << std::endl;
}
