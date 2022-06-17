#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<TreeNode*, vector<int> > memo;
public:
    int decrypt(bool b1, bool b2) { 
        if (!b1 and !b2) return 0;
        if (!b1 and b2) return 1;
        if (b1 and !b2) return 2;
        return 3;
    }
    int dp(bool watched, TreeNode * cur, bool mustPut) { 
        if (mustPut && !cur) { return INT_MAX - 50; }
        if (!cur) return 0;
        if (!cur->left && !cur->right) { 
            return watched ? 0 : 1;
        }
        auto itr = memo.find(cur);
        if (itr != memo.end())
            if (itr->second[decrypt(watched, mustPut)] > 0) return itr->second[decrypt(watched, mustPut)];
        int ans = 0;
        if (mustPut) { 
            ans = 1 + dp(true, cur->left, false) + dp(true, cur->right, false);
        }
        else if (watched) { 
            ans = std::min(1 + dp(true, cur->left, false) + dp(true, cur->right, false), dp(false, cur->left, false) + dp(false, cur->right, false));
        }
        else { 
            ans = std::min(1 + dp(true, cur->left, false) + dp(true, cur->right, false),
                            std::min(dp(false, cur->left, true) + dp(false, cur->right, false),
                                     dp(false, cur->left, false) + dp(false, cur->right, true)));
        }
        if (memo.find(cur) == memo.end()) { 
            vector<int> temp(4, 0);
            temp[decrypt(watched, mustPut)] = ans;
            memo.insert({cur, temp});
        }
        else { 
            memo.find(cur)->second[decrypt(watched, mustPut)] = ans;
        }
        return ans;
    }
    int minCameraCover(TreeNode * root) {
        this->memo = unordered_map<TreeNode*, vector<int> >();
        int ans = dp(false, root, false);        
        return ans;
    }
};