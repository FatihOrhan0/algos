#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) { 
            if (map1.find(target - nums[i]) != map1.end()) { 
                cout << i << endl;
                vector<int> temp = {map1.find(nums[i])->second, i}; return temp;
            }
            map1.insert({nums[i], i});
        }
        vector<int> temp;
        return temp;
    }

int main() { 
    vector<int> nums = {3, 2, 4};
    vector<int> res = twoSum(nums, 6);
    cout << res[0] << res[1];
}