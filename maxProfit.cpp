#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<vector<int> > > dp;
    vector<int> prices;
public:
    int dpHelper(int d, int TLeft, short haveBond) { 
        if (TLeft == 0) return 0;
        if (d == prices.size()) return 0;
        if (dp[d][TLeft - 1][haveBond] == -1) { 
            int ans;
            if (haveBond == 1) { 
                ans = std::max(prices[d] + dpHelper(d + 1, TLeft - 1, 0), dpHelper(d + 1, TLeft, 1));
            }
            else { 
                ans = std::max(dpHelper(d + 1, TLeft, 1) - prices[d], dpHelper(d + 1, TLeft, 0));
            }
            dp[d][TLeft - 1][haveBond] = ans;
        }
        return dp[d][TLeft - 1][haveBond];
    }
    int maxProfit(int k, vector<int> & prices) {
        if (k == 0 || prices.size() == 0) return 0;
        this->prices = prices;
        this->dp = vector<vector<vector<int> > >(prices.size(), 
        vector<vector<int> >(k, vector<int>(2, -1)));
        return dpHelper(0, k, 0);
    }
};

int main() { 
    Solution s;
    vector<int> test = {2, 4, 1};
    cout << s.maxProfit(2, test) << endl;
    return EXIT_SUCCESS;
}