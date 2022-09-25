//Solution to LC 46.
//Can be further improved by using lists and constructing the end 2d vector in the end. However, given the 
//low limits of the question, it's not necessary.

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:     
    vector<vector<int> > helper(vector<int> & nums, int index) { 
        if (index == 0) return {};
        if (index == 1) { return {{nums[0]}}; }
        if (index == 2) { 
            return {{nums[0], nums[1]}, {nums[1], nums[0]}};
        }
        auto prev = helper(nums, index - 1);
        int num = nums[index - 1];
        vector<vector<int> > ans;
        for (auto vec : prev) { 
            for (int i = 0; i < index - 1; i++) { 
                vector<int> temp = vec;
                temp.insert(temp.begin() + i, num);
                ans.push_back(temp);
            }
            vector<int> temp = vec;
            temp.push_back(num);
            ans.push_back(temp);
        }
        return ans;
        
    }
    vector<vector<int> > permute(vector<int> & nums) {
        return helper(nums, nums.size());
    }
};

int main() { 
    Solution s;
    vector<int> test = {1, 2, 3};
    vector<vector<int> > ans = s.permute(test);
    for (auto vec : ans) { 
        for (auto i : vec) { 
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}