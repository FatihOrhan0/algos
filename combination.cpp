#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtracker(int lastAdded, vector<int> & cur, int k, int n, vector<vector<int> > & ans) {
        if (n - lastAdded < k - cur.size()) return;
        if (lastAdded > n) return; 
        if (cur.size() == k) { 
            ans.push_back(cur);
        }
        while (lastAdded < n + 1 and lastAdded >= 0) { 
            if (!(lastAdded > n and n - lastAdded < k - cur.size()))  {
                cur.push_back(lastAdded + 1);
                backtracker(lastAdded + 1, cur, k, n, ans);
                cur.pop_back();
            }
            lastAdded++;
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> cur;
        backtracker(0, cur, k, n, ans);
        return ans;
    }
};

int main() { 
    Solution s;
    auto vec = s.combine(5, 3);
    for (auto i : vec) { 
        for (auto j : i) { 
            cout << j << " ";
        }
        cout << endl;
    }
    return 1;
}