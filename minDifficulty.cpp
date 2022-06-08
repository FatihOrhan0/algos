#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:    
    int d;
    vector<int> jobDifficulty;

public:
    int dpHelper(int i, int day, vector<vector<int> > & dp) { 
        if (day == d) {
            int max = INT_MIN;
            for (int j = i; j < jobDifficulty.size(); j++) { 
                max = std::max(max, jobDifficulty[j]);
            } 
            return max;
        }

        else if (dp[i][day] == -1) { 
            int min = INT_MAX, hardest = 0;
            for (int j = i; j < jobDifficulty.size() - (d - day); j++) { 
                hardest = std::max(jobDifficulty[j], hardest);
                min = std::min(min, hardest + dpHelper(j + 1, day + 1, dp));
            }
            dp[i][day] = min;
        }
        return dp[i][day]; 
    }
    int minDifficulty(vector<int> & jobDifficulty, int d) {
        int jobs = jobDifficulty.size();
        if (jobs < d) return -1;
        this->d = d;
        this->jobDifficulty = jobDifficulty;
        vector<int> oneRow(d + 1, -1);
        vector<vector<int> > dp(jobDifficulty.size(), oneRow);
        int ans = dpHelper(0, 1, dp);
        return ans;
    }
};

int main() { 
    Solution s;
    vector<int> difficulties = {11, 111, 22, 222, 33, 333, 44, 444};
    cout << s.minDifficulty(difficulties, 6);
}