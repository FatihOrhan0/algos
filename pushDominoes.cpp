//very simple solution to LC 838, Push Dominoes

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        for (int i = 0; i < dominoes.size(); i++) { 
            int rightForce = 0;
            if (dominoes[i] == '.') continue;
            else if (dominoes[i] == 'L') { 
                int j = i - 1;
                while (j >= 0 && dominoes[j] == '.') { 
                    dominoes[j] = 'L';
                    j--;
                }
            }
            else { 
                int j = i + 1;
                while (j < dominoes.size() && dominoes[j] == '.') { 
                    dominoes[j] = 'R';
                    rightForce++;
                    j++;
                }
                if (j == dominoes.size()) return dominoes;
                if (dominoes[j] == 'R') {
                    i = j - 1;
                    continue;
                }
                else {
                    int temp = rightForce / 2;
                    bool b = rightForce % 2;
                    for (int k = 0; k <= temp; k++) { 
                        dominoes[j - k] = 'L';
                    }
                    if (b) { 
                        dominoes[j - rightForce / 2 - 1] = '.';
                    }
                    i = j;
                }
            }
        }
        return dominoes;
    }
};

int main() { 
    Solution s;
    cout << s.pushDominoes("RR.L") << endl;
    return 0;
}