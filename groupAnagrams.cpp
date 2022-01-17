#include <vector>
#include <map>
#include <iostream>
#include <string>

//this problem comes from: 
//https://leetcode.com/problems/group-anagrams/

const int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 
59, 61, 67, 71, 73, 79, 83, 89, 97};

int encryptWord(const std::string & s) { 
    int e = 1;
    for (unsigned int i = 0; i < s.size(); i++) { 
        e *= primes[(int) (s[i] - 'a')]; 
    }
    return e;
}

std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string> & strs) {
    std::map<int, std::vector<std::string> > anagrams;
    for (unsigned int i = 0; i < strs.size(); i++) { 
        auto itr = anagrams.find(encryptWord(strs[i]));
        if (itr == anagrams.end()) { 
            std::vector<std::string> temp = {strs[i]};
            anagrams.insert({encryptWord(strs[i]), temp});
        }
        else { 
            anagrams.find(encryptWord(strs[i]))->second.push_back(strs[i]);
        }
    }
    std::vector<std::vector<std::string> > answer;
    for (auto itr = anagrams.begin(); itr != anagrams.end(); itr++) { 
        answer.push_back(itr->second);
    }
    return answer;
}

int main() { 
    std::vector<std::string> words = {"eat","tea","tan","ate","nat","bat"};
    auto answer = groupAnagrams(words);
    for(int i = 0; i < answer.size(); i++) { 
        for(int j = 0; j < answer[i].size(); j++) { 
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 1;
}