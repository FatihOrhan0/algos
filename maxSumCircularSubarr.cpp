//Solution to https://leetcode.com/problems/maximum-sum-circular-subarray/

#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> & nums) {
        if (nums.size() == 1) return nums[0];
        int cur = 0, max = INT_MIN, lastPos = 0, n = nums.size();
        for (int i = 0; i < 2 * nums.size(); i++) { 
            if (i >= nums.size() && lastPos == i % n) {
                if (cur <= 0) return max;
                int min = 0;
                int cur2 = 0;
                for (int j = lastPos; j < lastPos + n - 1; j++) { 
                    cur2 += nums[j % n];
                    if (cur2 > 0) cur2 = 0;
                    min = std::min(min, cur2);
                }
                return std::max(cur - min, max);
            }
            cur += nums[i % n];
            max = std::max(cur, max);
            if (cur < 0) { 
                lastPos = i + 1;
                cur = 0;
            }
        }
        return max;
    }
};

int main() { 
    vector<int> test = {9, 7, -6, 7, 9, -10, 5, 9, 0, -1};
    Solution s;
    cout << s.maxSubarraySumCircular(test) << endl;
    return 1;
}