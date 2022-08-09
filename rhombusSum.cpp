#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef vector<vector<int>>& vvi;

class Solution {
public:
    vector<int> calcSquare(vvi grid, int row, int col) { 
        vector<int> heap;
        for (int i = 0; row - i >= 0 && col + 2 * i < grid[0].size() && row + i < grid.size(); i++) { 
            int area = 0;
            if (i == 0) {
                area = grid[row][col];
            }
            else { 
                for (int j = 0; j <= i; j++) { 
                    area += grid[row - j][col + j];
                    if (j > 0) {
                        area += grid[row - i + j][col + i + j];
                        area += grid[row + j][col + 2 * i - j];
                        if (j < i)
                            area += grid[row + i - j][col + i - j];
                    }
                }
            }
            heap.push_back(area);
            sort(heap.begin(), heap.end(), [] (int x, int y) -> bool { return x > y; });
            if (heap.size() > 3) heap.pop_back();
        }
        return heap;
    }
    vector<int> getBiggestThree(vector<vector<int> > & grid) {
        vector<int> ans;
        for (int i = 0; i <= grid.size(); i++) { 
            for (int j = 0; j < grid[0].size(); j++) { 
                vector<int> temp = calcSquare(grid, i, j);
                for (int k : temp) { 
                    bool found = false;
                    for (int t : ans) { 
                        if (t == k) found = true;
                    }
                    if (found) continue;
                    ans.push_back(k);
                    sort(ans.begin(), ans.end(), [] (int x, int y) -> bool { return x > y; });
                    if (ans.size() == 4) ans.pop_back();
                }
            }
        }
        
        return ans;
    }
};

int main() { 
    Solution s;
    vector<vector<int> > grid = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    s.getBiggestThree(grid);
    return 1;
}