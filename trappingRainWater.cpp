#include <iostream>
#include <vector>
#include <algorithm>
// #include

//a helper function to find the max number's index from given index excluding the given index
//returns 0 if the target index is not reasonable
std::pair<int, int> findMax(const std::vector<int> & vec, int target) { 
    int max = 0;
    int maxIndex = -1;
    target++;
    while (target < (int) vec.size()) { 
        if (vec[target] >= max) { 
            max = vec[target];
            maxIndex = target;
        }
        target++;
    }

    return std::make_pair(max, maxIndex);
}

//This file is a solution to the below problem
//https://leetcode.com/problems/trapping-rain-water/submissions/
//TODO: reconsider the last segment.

/* 
    *General structure of the algorithm: 
    *span through the trailing zeros at the beginning 
    *for the first nonzero value, keep traversing if the upcoming numbers are greater than the current.
    *when the series starts decreasing, find a value that is greater thatn or equal to the starting value
    *add the water in between the two values. 
    *if no such value is found increase the left index.
*/

int trap(const std::vector<int> & height) { 
    int total = 0;
    unsigned int leftIndex = 0;
    while (leftIndex < height.size()) { 
    //skip to the decreasing part
    while (leftIndex < height.size() - 1 && height[leftIndex] <= height[leftIndex + 1]) { 
        leftIndex++;
    }
    unsigned int tempIndex = leftIndex;
    tempIndex++;
    while (tempIndex < height.size() && height[tempIndex] < height[leftIndex]) { 
        tempIndex++;
    }
    if (tempIndex == height.size()) { 
        std::pair<int, int> max = findMax(height, leftIndex);
        if (leftIndex == height.size() - 1) { return total; }
        leftIndex++;
        for (; leftIndex < (unsigned int) max.second; leftIndex++) { 
            total += max.first - height[leftIndex];
        }
        continue;
    }
    else { 
        for (unsigned int tempIndex2 = leftIndex; tempIndex2 < tempIndex; tempIndex2++) { 
            total += height[leftIndex] - height[tempIndex2];
        }
    }
    leftIndex = tempIndex;
    }
    return total;
}

int main() { 
    std::vector<int> heights = {0, 2, 0};
    std::vector<int> heights2 = {2, 0, 0,0, 8};
    std::cout << trap(heights) << std::endl;
    std::cout << trap(heights2);
}
