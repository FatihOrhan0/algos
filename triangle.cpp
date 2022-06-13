//solution to https://leetcode.com/problems/triangle/solution/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int> > & triangle) {
    if (triangle.size() == 1) return triangle[0][0];
    vector<vector<int> > dp;
    for (int i = 0; i < triangle.size(); i++) { 
        dp.push_back(vector<int>(triangle[i].size(), INT_MAX));
    }
    int ans = INT_MAX;
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.size() - 1; i++) { 
        for (int j = 0; j < triangle[i].size(); j++) { 
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
            if (i == triangle.size() - 2) { 
                ans = std::min(ans, std::min(dp[i + 1][j], dp[i + 1][j + 1]));
            }
        }
    }
    return ans;
}

int main() { 
    vector<vector<int> > triangle = [{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
}