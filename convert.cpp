#include <vector>
#include <string>
#include <iostream>

std::string convert(std::string s, int numRows) { 
    if (numRows == 1 || numRows >= s.size() ) { return s; }
    std::vector<std::string> rows(numRows); 
    for (unsigned int i = 0; i < s.size(); i++) {
        unsigned short j = 0; 
        unsigned short k = 0; 
        for (; j < numRows; j++, k++) { 
            if (j + i < s.size()) { 
                rows[j] += (char) s[i + j];
            }
        }
        j -= 2;

        for (; j > 0; j--, k++) { 
            if ((i + k) < s.size()) { 
                rows[j] += (char) s[i + k];
            }
        }
        i += 2 * numRows - 3;
    }
    std::string answer;
    for (unsigned int i = 0; i < rows.size(); i++) { 
        answer += rows[i];
    }
   return answer;
}

int main() { 
    std::string abc = convert("a", 1);
    std::cout << abc;
}