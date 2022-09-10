#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int deleteAndEarn(vector<int> & nums) {
    unordered_map<int, int> hash;
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < nums.size(); i++) { 
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
        if (hash.find(nums[i]) == hash.end()) { 
            hash.insert({nums[i], 1});
        }
        else { 
            hash.find(nums[i])->second++;
        }
    }
    if (hash.size() == 1) { return hash.begin()->first * hash.begin()->second; }
    vector<int> dp(max - min + 1, 0);
    for (auto itr : hash) { 
        dp[itr.first - min] = itr.first * itr.second;
    }
    dp[0] = hash.find(min)->first * hash.find(min)->second;
    hash.erase(min);
    int secondMin = INT_MAX;

    for (auto itr : hash) { 
        if (itr.first < secondMin) { secondMin = itr.first; }
    }

    dp[secondMin - min] = std::max(dp[secondMin - min - 1], hash.find(secondMin)->first * hash.find(secondMin)->second); 
    if (secondMin - min > 1) {
        dp[secondMin - min] += dp[0];
    }
    for (int i = secondMin - min + 1; i < dp.size(); i++) {
        if (hash.find(i) == hash.end()) { 
            dp[i] = dp[i - 1];
        }
        else {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + hash.find(i)->first * hash.find(i)->second);
        }        
    }
    return dp[dp.size() - 1];
}


int main() { 
    vector<int> sample = {2,2,2,3,3,5,5,6,6,6,8,8,8,8,9,9,9,9,10,10};
    cout << deleteAndEarn(sample) << endl;
    return EXIT_SUCCESS;
}
