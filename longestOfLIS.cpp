#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<unordered_map<int, int> > dp;
    vector<int> nums;

public:
    int dpHelper(int biggest, int i) { 
        if (i == nums.size()) return 0;
        if (dp[i].find(biggest) != dp[i].end()) return dp[i].find(biggest)->second;
        if (nums[i] <= biggest) return dpHelper(biggest, i + 1);
        int ans = std::max(1 + dpHelper(std::max(biggest, nums[i]), i + 1), dpHelper(biggest, i + 1));
        dp[i].insert({biggest, ans});
        return ans;
    }
    int lengthOfLIS(const vector<int> & nums) {
        this->nums = nums;
        if (nums.size() < 2) return nums.size();
        this->dp = vector<unordered_map<int, int> > (nums.size(), unordered_map<int, int>());
        // this->dp = singleRow;
        return dpHelper(INT_MIN, 0);
    }
};

int main() { 
    Solution s;
    vector<int> nums = {0,1,0,3,2,3};
    cout << s.lengthOfLIS(nums);
    return 1;
}