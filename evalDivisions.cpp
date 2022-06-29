#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Disjoint { 
public:
    
    vector<int> roots;
    vector<double> ratios;
    
    Disjoint(const int n) : roots(n), ratios(n) { 
        for (int i = 0; i < n; i++) { 
            roots[i] = i;
            ratios[i] = INT_MIN;
        }
    }
    int find(int n) { 
        while (roots[n] != n) n = roots[n];
        return n;
    }
    
    void unionSet(const int n1, const int n2, const double ratio) { 
        if (ratios[n1] == INT_MIN) ratios[n1] = 1;
        if (ratios[n2] == INT_MIN) ratios[n2] = 1;
        int r1 = find(n1);
        int r2 = find(n2);
        if (r1 != r2) { 
            ratios[r2] = (ratio * ratios[n1]) / ratios[n2];
            roots[r2] = r1;
            for (int i = 0; i < roots.size(); i++) { 
                if (roots[i] == r2) { 
                    roots[i] = r1;
                    ratios[i] *= ratios[r2];
                }
            }
        }
    }
    
    bool isConnected(const int n1, const int n2) { 
        return find(n1) == find(n2);
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string> > & equations, vector<double> & values, vector<vector<string> > & queries) {
        Disjoint d(40);
        int empty = 0;
        unordered_map<string, int> hash;
        for (int i = 0; i < equations.size(); i++) { 
            int temp1, temp2;
            if (hash.find(equations[i][0]) == hash.end()) { 
                temp1 = empty;
                hash.insert({equations[i][0], temp1});
                empty++;
            }
            else {
                temp1 = hash.find(equations[i][0])->second;
            }
            if (hash.find(equations[i][1]) == hash.end()) { 
                temp2 = empty;
                hash.insert({equations[i][1], temp2});
                empty++;
            }
            else {
                temp2 = hash.find(equations[i][1])->second;
            }
            d.unionSet(temp1, temp2, values[i]);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) { 
            if (hash.find(queries[i][0]) == hash.end()) {
                ans.push_back(-1);
                continue;
            }
            if (hash.find(queries[i][1]) == hash.end()) {
                ans.push_back(-1);
                continue;
            }
            int temp1 = hash.find(queries[i][0])->second, temp2 = hash.find(queries[i][1])->second;
            if (!d.isConnected(temp1, temp2)) {
                ans.push_back(-1);
                continue;
            }
            if (d.ratios[temp1] == INT_MIN || d.ratios[temp2] == INT_MIN) {
                cout << temp1 << " " << temp2 << endl;
                ans.push_back(-1);
                continue;
            }
            ans.push_back(d.ratios[temp2] / d.ratios[temp1]);
        }
        return ans;
    }
};