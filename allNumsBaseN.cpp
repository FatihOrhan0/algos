/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void printVec(const vector<int> & vec) { 
    for (int i : vec) { cout << i << " ";}
    cout << endl;
}

void printer(int n) { 
    vector<int> nums(n, 0);   
    for (int i = 0;; i++) {
        printVec(nums);
        for (auto itr = nums.rbegin(); itr != nums.rend(); itr++) { 
            if (*itr == n) { 
                *itr = 0;
                if (itr == (--nums.rend())) return; 
            }
            else { 
                *itr = *itr + 1;
                break;
            }
        }
    }
}

int main() {
    printer(5);

    return 0;
}
