#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// Linear time routine for partitioning step of Quicksort
int partition(vector<int> & nums) {
    int pIndex = 0;
 
    // each time we find a positive number, `pIndex` is incremented, and
    // that element would be placed before the pivot
    for (int i = 0; i < (int) nums.size(); i++) {
        if (nums[i] > 0) {
            swap(nums[i], nums[pIndex]);
            pIndex++;
        }
    }

    for (int i = 0; i < (int) nums.size(); i++) { 
        cout << nums[i] << endl;
    }
 
    // return index of the first non-positive number
    return pIndex;
}
 
// Function to find the smallest missing positive number from an unsorted array
int findSmallestMissing(vector<int> nums) {
    int k = partition(nums);
 
    // Case 1. The missing number is in range 1 to k
 
    // do for each array element
    for (int i = 0; i < k; i++) {
        // get the value of the current element
        int val = abs(nums[i]);
 
        // make element at index `val-1` negative if it is positive
        if (val-1 < k && nums[val-1] >= 0) {
            nums[val-1] = -nums[val-1];
        }
    }
    cout << "second: " << endl;
    for (int i = 0; i < (int) nums.size(); i++) { 
        cout << nums[i] << endl;
    }
 
    // check for missing numbers from 1 to k
    for (int i = 0; i < k; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
 
    // Case 2. If numbers from 1 to k are present in the array,
    // then the missing number is `k + 1` e.g. {1, 2, 3, 4} —> 5
 
    return k + 1;
}
 
int main() {
    vector<int> nums = { 1, 2, -1, 6, 5, 3 };
    int n = findSmallestMissing(nums);
    cout << "The smallest positive missing number is " << n;
    return 0;
}