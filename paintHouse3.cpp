#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    int hc, target;
    vector<vector<vector<int>>> memo;
    vector<vector<int>> cost;
    int dp(int neighbors, int index, int lastColor) { 
        cout << neighbors << " " << index << " " << lastColor << endl;
        if (neighbors > target) return INT_MAX;
        if (hc - (index + 1) < target - neighbors) return INT_MAX;
        if (index == hc) { 
            if (neighbors == target) { 
                return cost[index][lastColor];
            }
            int minCost = INT_MAX;
            for (int color = 0; color < cost[index].size(); color++) {
                if (color != lastColor)
                    minCost = std::min(color, minCost);
            }
            if (lastColor != -1)
                memo[neighbors][index][lastColor] = minCost;
            return minCost;
        }
        if (neighbors == target) { 
            int sum = 0;
            while (index < hc) { 
                sum += cost[index][lastColor];
                index++;
            }
            if (lastColor != -1)
                memo[neighbors][index][lastColor] = sum;
            return sum;
        }
        
        if (lastColor != -1 && memo[neighbors][index][lastColor] != -1) return memo[neighbors][index][lastColor];
        //go through the cost's index and find the best choice.
        int ans = INT_MAX, cp = 0;
        for (int i = 0; i < cost[index].size(); i++) { 
            if (i == lastColor) { 
                int temp = dp(neighbors, index + 1, lastColor);
                if (ans > temp) { 
                    ans = temp;
                    cp = lastColor;
                }                
            }
            else { 
                int temp = dp(neighbors + 1, index + 1, i);
                if (ans > temp) { 
                    ans = temp;
                    cp = i;
                }
            }
        }
        if (lastColor != -1)
            memo[neighbors][index][lastColor] = ans;
        return ans + cost[index][cp];
    }
    int minCost(vector<int> & houses, vector<vector<int> > & cost, int m, int n, int target) {
        this->target = target;
        hc = m;
        memo = vector<vector<vector<int>>>(target + 1, vector<vector<int>>(m + 1, vector<int>(n, -1)));
        this->cost = cost;
        return dp(0, 0, -1);
    }
};


int main() { 
    Solution s;
    vector<int> houses = {0, 2, 1, 2, 0};
    vector<vector<int> > cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
    cout << s.minCost(houses, cost, 5, 2, 3) << endl;
    return 1;   
}