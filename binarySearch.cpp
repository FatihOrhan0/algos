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

//binary search for duplicates problem: https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int binarySearch(vector<int> & nums, int left, int right) {
        int mid = left + (right - left) / 2;
        if (left >= right) return nums[right];
        if (nums[mid - 1] != nums[mid] and nums[mid + 1] != nums[mid]) return nums[mid];
        if (nums[mid - 1] == nums[mid]) { 
            if ((mid - 1 - left) % 2 == 0) return binarySearch(nums, mid + 1, right);
            else { return binarySearch(nums, left, mid - 2); }
        }
        else { 
            if ((right - mid + 1) % 2 == 0) return binarySearch(nums, left, mid - 1);
            else { return binarySearch(nums, mid + 2, right); }
        }
        
    }
    int singleNonDuplicate(vector<int> & nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};

int main() { 
    std::vector<int> abc;
    for (double i = 0; i < 2000; i++) { 
        abc.push_back(i);
    }
    std::cout << binarySearch<int>(abc, -6);
}