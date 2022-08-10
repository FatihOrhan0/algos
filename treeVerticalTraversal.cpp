#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, vector<pair<int, int> > > hash;
    void helper(TreeNode * root, int level, int level2, int & min, int & max) { 
        if (!root) return;
        min = std::min(min, level);
        max = std::max(max, level);
        hash[level].push_back({level2, root->val});
        helper(root->left, level - 1, level2 + 1, min, max);
        helper(root->right, level + 1, level2 + 1, min, max);
    }
    vector<vector<int>> verticalOrder(TreeNode * root) {
        if (!root) return {};
        int min = INT_MAX, max = INT_MIN;
        helper(root, 0, 0, min, max);
        vector<vector<int> > ans(max - min + 1);
        for (auto itr : hash) { 
            sort(itr.second.begin(), itr.second.end(), [&] (pair<int, int> p1, pair<int, int> p2) -> bool {return p1.first < p2.first; });
            for (auto pair : itr.second)
                ans[itr.first - min].push_back(pair.second);
        }
        return ans;        
    }
};