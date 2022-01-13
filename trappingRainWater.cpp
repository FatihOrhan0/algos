#include <iostream>
#include <vector>

//This file is a solution to the below problem
//https://leetcode.com/problems/trapping-rain-water/submissions/
//TODO: reconsider the last segment.

int trap(const std::vector<int> & height) { 
    int total = 0;
    unsigned int leftIndex = 0;
    while (leftIndex < height.size() && height[leftIndex] == 0) { 
        leftIndex++;
    }
    while (leftIndex < height.size()) {
        std::cout << leftIndex << " " << total << std::endl;
        if (leftIndex == height.size() - 1) { 
            return total;
        } 
        if (leftIndex + 1 < height.size() && height[leftIndex + 1] >= height[leftIndex]) { 
            leftIndex++;
            continue;
        }
        unsigned int localIndex = leftIndex + 1;
        unsigned int localIndex2 = leftIndex;
        bool exceed = false;
        while (height[localIndex] < height[leftIndex]) { 
            localIndex++;
            if (localIndex == height.size()) { 
                exceed = true;
                break;
            }
            // consider the boundary case here.
        }
        if (exceed) { 
            leftIndex++;
            continue;
        }
        unsigned int min = std::min(height[localIndex], height[leftIndex]);
        while (localIndex2 < localIndex) { 
            total += min - height[localIndex2];
            localIndex2++;
        }
        leftIndex = localIndex;
    }
    return total;
}

int main() { 
    std::vector<int> heights = { 4,2,0,3,2,5 };
    std::cout << trap(heights);
}
