#include <iostream>
#include <vector>


//a function to print values of a given vector templated over class T.
template <class T>
void printVec(const std::vector<T> & sv) { 
    for (unsigned int i = 0; i < sv.size(); i++) { 
        std::cout << sv[i] << " ";
    }
    return;
}

//a very simple function to linearly search a given value in a vector
//returns the index of the given value. if not found, returns -1
template <class T> 
int linearSearch(const std::vector<T> & sv, const T & val) { 
    for (unsigned int i = 0; i < sv.size(); i++) { 
        if (sv[i] == val) { return i; }
    }
    return -1;
}

//a binary search function for a vector templated over variable T. 
//returns the index of the value. if not found, returns -1.
template <class T>
int binarySearch(const std::vector<T> & sv, const T & val) { 
    unsigned int len = sv.size(), mid = len / 2, start = 0, end = len; 
    while (true) { 
        std::cout << start << " " << mid << std::endl;
        if (sv[mid] == val) { 
            return mid;
        }
        else if (start == mid) return -1;
        else if (sv[mid] < val) { 
            start = mid;
            mid = (mid + end) / 2;
        }
        else { 
            end = mid;
            mid = (mid + start) / 2;
        }
    }
    return mid;
}

int main() { 
    std::vector<int> abc;
    for (double i = 0; i < 2000; i++) { 
        abc.push_back(i);
    }
    std::cout << binarySearch<int>(abc, -6);
}