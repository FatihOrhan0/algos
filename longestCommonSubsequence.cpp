#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    string text1, text2;
    vector<vector<int> > dp;
public:
    int helper(int pos1, int pos2) { 
        if (pos1 == text1.size() || pos2 == text2.size()) { 
            return 0;
        } 
        if (dp[pos1][pos2] != -1) return dp[pos1][pos2];
        int loc;
        for (int i = pos2; i < text2.size(); i++) { 
            if (text2[i] == text1[pos1]) { 
                int ans = std::max(helper(pos1 + 1, pos2), 1 + helper(pos1 + 1, i + 1));
                dp[pos1][pos2] = ans;
                return ans;
            }
        }
        int ans = helper(pos1 + 1, pos2);
        dp[pos1][pos2] = ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        // first make sure second text is not longer than the first
        if (text1.size() < text2.size()) { 
            std::swap(text1, text2);
        }
        vector<int> row(text2.size(), -1);
        this->dp = vector<vector<int> >(text1.size(), row);
        this->text1 = text1;
        this->text2 = text2;
        return helper(0, 0);
    }
};


int main() { 
    Solution s1;
    cout << s1.longestCommonSubsequence("abcba", "abcbcba");
    return 1;
}