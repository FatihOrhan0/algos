#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int leftG, int leftN, int lastSize, vector<vector<vector<int> > > & memo) { 
    if (leftN == 0 and leftG == 0) return 1;
    if (lastSize > leftN) return 0;
    if (leftG > leftN) return 0;
    if (leftG < 0) return 0;
    if (leftN < 0) return 0;
    if (lastSize == leftN) { 
        return (leftG == 0) ? 1 : 0;
    }
    if (memo[leftG][leftN][lastSize] != -1) return memo[leftG][leftN][lastSize];
    int ans = 0;
    for (int i = lastSize + 1; i <= leftN; i++) { 
        ans += dp(leftG - 1, leftN - i, i, memo);
    }
    if (lastSize != 0)
        ans += dp(leftG, leftN - lastSize, lastSize, memo);
    memo[leftG][leftN][lastSize] = ans;
    return ans;
}

int grouping(int n, int k) { 
    if (k > n) return 0;   
    if (n == k) return 1;
    if (n == 0) return 1;
    if (k == 0) return 1;
    vector<vector<vector<int> > > memo = 
    vector<vector<vector<int> > >(k + 1, vector<vector<int> >(n + 1, vector<int>(n + 1, -1)));
    return dp(k, n, 0, memo);
}
    
int main()
{
    cout << grouping(5, 2) << endl; 
    return 0;
}