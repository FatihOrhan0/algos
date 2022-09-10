#include <string>
#include <iostream>

using namespace std;

string longestPalindrome(string s) {
    string smax = "";
    for (int i = 0; i < s.size(); i++) {
        int offset = 1;
        while (i - offset >= 0 && i + offset < s.size()) { 
            if (s[i - offset] != s[i + offset]) { 
                break;
            }
            offset++;
        }

        cout << "test1 " << i << " " << offset << endl;
        
        
        if (2 * offset > smax.size() && i - offset >= 0 && i + offset - 1 < s.size()) { 
            smax = s.substr(i - offset, 2 * offset);
        }
        offset = 0;
        while (i - offset >= 0 && i + offset < s.size()) { 
            if (s[i - offset] != s[i + offset + 1]) break;
            offset++;
        }

        cout << "test2 " << i << " " << offset << endl;

        if (2 * offset + 1 > smax.size() && i - offset + 1 >= 0 && i + offset < s.size()) { 
            smax = s.substr(i - offset - 1, 2 * offset + 1);
        }
    }
    return smax;
}


int main() { 
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 1;
}