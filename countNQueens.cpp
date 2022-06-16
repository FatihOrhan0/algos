#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
private: 
    int n;

public:
    void placeQueen(vector<vector<int> > & board, int pos) { 
        int row = ((pos - 1) / n);
        int col = (pos - 1) % n;
        if (row < 0 or col < 0) cout << "error zero";
        if (row >= n or col >= n) cout << "error bound";
        board[row][col]++;
        for (int i = 1; i < n; i++) { 
            if (row + i < n and col + i < n) { 
                board[row + i][col + i]++;
            }
            if (row + i < n) { 
                board[row + i][col]++;
            }
            if (col + i < n) { 
                board[row][col + i]++;
            }
            if (row - i >= 0 and col - i >= 0) { 
                board[row - i][col - i]++;
            }
            if (col - i >= 0) { 
                board[row][col - i]++;
            }
            if (row - i >= 0) { 
                board[row - i][col]++;
            }
            if (row + i < n and col - i >= 0) { 
                board[row + i][col - i]++;
            }
            if (row - i >= 0 and col + i < n) { 
                board[row - i][col + i]++;
            }
        }
    }
    void removeQueen(vector<vector<int> > & board, int pos) { 
        int row = ((pos - 1) / n);
        int col = (pos - 1) % n;
        board[row][col]--;
        for (int i = 1; i < n; i++) { 
            if (row + i < n and col + i < n) { 
                board[row + i][col + i]--;
            }
            if (row + i < n) { 
                board[row + i][col]--;
            }
            if (col + i < n) { 
                board[row][col + i]--;
            }
            if (row - i >= 0 and col - i >= 0) { 
                board[row - i][col - i]--;
            }
            if (col - i >= 0) { 
                board[row][col - i]--;
            }
            if (row - i >= 0) { 
                board[row - i][col]--;
            }
            if (row + i < n and col - i >= 0) { 
                board[row + i][col - i]--;
            }
            if (row - i >= 0 and col + i < n) { 
                board[row - i][col + i]--;
            }
        }
    }
    
    int findFirstEmpty(const vector<vector<int> > & board, int pos) { 
        int row = ((pos - 1) / n);
        int i = row + 1; 
        if (row + 1 >= n) return INT_MAX;
        for (int j = 0; j < n; j++) { 
            if (board[i][j] == 0) { 
                // cout << "empty" << endl;
                return i * n + j + 1;
                // cout << ans << endl;    
            }
        }
        return INT_MAX;
    }
    
    int countQueens(int placed, int pos, vector<vector<int> > & board) { 
        int ans = 0;
        if (placed == n) return 1;
        
        while (pos <= (placed + 1) * n) { 
            int row = ((pos - 1) / n);
            int col = (pos - 1) % n;
            if (board[row][col] == 0) { 
                placeQueen(board, pos);
                placed++;
                /* if (placed == 1) {
                    cout << "4\n";
                    for (auto i : board) { 
                        for (auto j : i) { 
                            cout << j << " ";
                        }
                        cout << endl;
                    }
                }
                if (placed == 2) cout << "5\n"; */
                if (placed == n) ans++;
                int nextPos = findFirstEmpty(board, pos);
                if (nextPos <= n * n) { 
                    ans += countQueens(placed, nextPos, board);
                }
                removeQueen(board, pos);
                placed--;
            }
            pos++;
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        //if (n == 1) return 1;
        // if (n < 4) return 0;
        vector<vector<int> > board(n, vector<int>(n, 0));
        this->n = n;
        return countQueens(0, 1, board);
    }
};

int main() { 
    Solution s;
    cout << s.totalNQueens(2) << endl;
    cout << s.totalNQueens(7) << endl;
    cout << s.totalNQueens(8) << endl;
    cout << s.totalNQueens(9) << endl;
    return 1;
}