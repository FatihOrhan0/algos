#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int temp = 1;
        for (int i = 0; i <= n / 2; i++) {
            for (int j = i; j < n - i; j++) { 
                matrix[i][j] = temp; 
                temp++;
            }
            for (int j = i + 1; j < n - i; j++) { 
                matrix[j][n - i - 1] = temp;
                temp++;
            }
            for (int j = n - i - 2; j >= i; j--) { 
                matrix[n - i - 1][j] = temp;
                temp++;
            }
            for (int j = n - i - 2; j > i; j--) { 
                matrix[j][i] = temp;
                temp++;
            }
        }
        return matrix;
    }
};

int main() { 
    Solution s;
    auto vec = s.generateMatrix(3);
    for (auto v : vec) { 
        for (int i : v) { 
            cout << i << " ";
        }
        cout << endl;
    }
}