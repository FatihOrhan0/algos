#include <iostream>
#include <vector>

using namespace std;

class Disjoint { 
public:
    
    vector<int> roots;
    vector<int> ranks;
    
    Disjoint(const int n) { 
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

class Solution {
public:
    int findCircleNum(vector<vector<int> > & isConnected) {
        int n = isConnected.size();
        Disjoint d(n);
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (isConnected[i][j] == 1) {
                    d.unionSet(i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < d.roots.size(); i++) { 
            cout << d.roots[i] << endl;
            if (d.roots[i] == i) count++;
        }
        return count;
    }
    bool validTree(int n, vector<vector<int>> & edges) {
        Disjoint d(n);
        for (auto vec : edges) { 
            d.unionSet(vec[0], vec[1]);
        }
        int count = 0;
        for (int i = 0; i < d.roots.size(); i++) { 
            if (d.roots[i] == i) { count++; }
        }
        return count == 1 && edges.size() == n - 1;
    }
};

int main() { 
    Solution s;
    vector<vector<int> > test = {{1,1,0},{1,1,0},{0,0,1}};
    cout << s.findCircleNum(test);

    return EXIT_SUCCESS;
}

