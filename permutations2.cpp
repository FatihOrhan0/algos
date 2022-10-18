//backtracking solution to permutation with repetitions
//for practice only, std::next_permutation() runs much faster

#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > ans;
    void helper(vector<int> cur, list<int> nums) { 
        if (nums.size() == 0) {
            ans.push_back(cur);
            return;
        }
        unordered_set<int> usedNums;
        for (auto itr = nums.begin(); itr != nums.end(); ) { 
            int temp = *itr;
            if (usedNums.find(temp) != usedNums.end()) {
                itr++;
                continue;
            }
            cur.push_back(temp);
            itr = nums.erase(itr);
            helper(cur, nums);
            nums.push_back(temp);
            cur.pop_back();
            usedNums.insert(temp);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> & nums) {
        // ans = vector<vector<int> >();
        list<int> n;
        for (int i : nums) n.push_back(i);
        vector<int> cur;
        helper(cur, n);
        return ans;
    }
};

int main() { 
    Solution s;
    vector<int> test = {1, 1, 2};
    auto ans = s.permuteUnique(test);
    for (auto vec : ans) { 
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 1;
}