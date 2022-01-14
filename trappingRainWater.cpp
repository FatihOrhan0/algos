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
        // std::cout << leftIndex << " " << height[leftIndex] << " " << total << std::endl; 
        if (height[leftIndex + 1] >= height[leftIndex]) { 
            leftIndex++;
            continue;
        }

        unsigned int localIndex = leftIndex + 1;
        unsigned int localIndex2 = leftIndex;
        bool exceed = false;
        while (height[localIndex] <= height[leftIndex]) { 
            localIndex++;
            if (localIndex == height.size()) { 
                exceed = true;
                break;
            }
        }

        if (exceed) { 
            localIndex = leftIndex + 1;
            int max = height[leftIndex + 1];
            int maxIndex = leftIndex + 1;
            bool increased = false; 
            while (localIndex < height.size()) { 
                if (height[localIndex] > height[localIndex - 1]) { 
                    increased = true;
                }
                if (height[localIndex] >= max) {
                    max = height[localIndex];
                    maxIndex = localIndex;
                }
                localIndex++;
            }
            std::cout << max << " " << total << std::endl;
            if (!increased) { 
                return total;
            }
            leftIndex++;
            for (; leftIndex < maxIndex; leftIndex++) { 
                total += max - height[leftIndex];
                // std::cout << leftIndex << " aa " << max << " " << total << std::endl;
            }
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
    std::vector<int> heights = {5, 4, 1, 2};
    std::cout << trap(heights);
}
