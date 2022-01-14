#include <iostream>
#include <vector>
#include <algorithm>

//This file is a solution to the below problem
//https://leetcode.com/problems/trapping-rain-water/submissions/
//TODO: reconsider the last segment.

int trap(const std::vector<int> & height) { 
    int total = 0;
    unsigned int leftIndex = 0;
    while (leftIndex < height.size() - 1) {

        if (height[leftIndex + 1] >= height[leftIndex]) { 
            leftIndex++;
            continue;
        }

        unsigned int localIndex = leftIndex + 1;
        unsigned int localIndex2 = leftIndex + 1;
        bool exceed = false;
        while (height[localIndex] <= height[leftIndex]) { 
            localIndex++;
            if (localIndex == height.size()) { 
                exceed = true;
                break;
            }
        }

        if (exceed) { 
            std::vector<int> temp(height.size() - leftIndex);
            for (unsigned int i = 0; i < height.size() - leftIndex; i++) { 
                temp[i] = height[leftIndex + 1];
            }
            std::reverse(temp.begin(), temp.end());
            total += trap(temp);
            return total;
        }
        
        unsigned int min = std::min(height[localIndex], height[leftIndex]);
        while (localIndex2 < localIndex) { 
            total += min - height[localIndex2];
            localIndex2++;
        }
        leftIndex = localIndex;
        leftIndex++;
    }
    std::cout << "total: " << total << std::endl;
    return total;
}

int main() { 
    std::vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << "trap: " << trap(heights);
}
