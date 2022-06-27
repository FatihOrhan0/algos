#include <iostream>
#include <vector>

using namespace std;

class Disjoint { 
public:
    vector<int> roots;
    vector<int> ranks;
    int count;
    
    Disjoint(const int n) { 
        count = n;
        roots = vector<int>(n, 0);
        ranks = vector<int>(n);
        for (int i = 0; i < n; i++) { 
            ranks[i] = 1;
            roots[i] = i;
        }
    }
    int find(const int n) { 
        if (roots[n] == n) return n;
        return roots[n] = find(roots[roots[n]]);
    }
    
    void unionSet(const int n1, const int n2) { 
        int r1 = find(n1);
        int r2 = find(n2);
        if (roots[r1] != roots[r2]) { 
            count--;
            if (ranks[r1] > ranks[r2]) {
                roots[r2] = r1;
            }
            else if (ranks[r2] > ranks[r1]) { 
                roots[r1] = r2;
            }
            else { 
                roots[r2] = r1;
                ranks[r1]++;
            }
        }
    }
    
    bool isConnected(const int n1, const int n2) { 
        return find(n1) == find(n2);
    }
};

bool comp(const vector<int> & v1, const vector<int> & v2) { 
    return v1[0] < v2[0];
}

class Solution {
public:
    int earliestAcq(vector<vector<int>> & logs, int n) {
        sort(logs.begin(), logs.end(), comp);
        Disjoint d(n);
        for (auto vec : logs) { 
            d.unionSet(vec[1], vec[2]);
            if (d.count == 1) return vec[0];
        }
        return -1;
    }
};