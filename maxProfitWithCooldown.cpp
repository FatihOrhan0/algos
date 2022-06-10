#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > dp;
    vector<int> prices;
    int dpHelper(int i, short haveStock) { 
        if (i >= prices.size()) return 0;
        int ans;
        if (dp[i][haveStock] == -1) { 
            if (haveStock) { 
                ans = std::max(prices[i] + dpHelper(i + 2, false), dpHelper(i + 1, true));
            }
            else { 
                ans = std::max(dpHelper(i + 1, true) - prices[i], dpHelper(i + 1, false));
            }
            dp[i][haveStock] = ans;
        }
        return dp[i][haveStock];
    }
    int maxProfit(vector<int> & prices) {
        if (prices.size() < 2) return 0;
        this->prices = prices;
        this->dp = vector<vector<int> >(prices.size(), vector<int>(2, -1));
        return dpHelper(0, false);
    }
};

int main() { 
    Solution s;
    vector<int> test = {1, 2, 3, 0, 2};
    cout << s.maxProfit(test) << endl;
    return EXIT_SUCCESS;
}