#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>



using namespace std;

void revert(std::unordered_map<char, std::pair<int, int> > & letters)     { 
    for (auto itr = letters.begin(); itr != letters.end(); itr++) { 
        itr->second.first = itr->second.second;
    }
}
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, pair<int, int> > letters;
    vector<int> answer;
    for (unsigned int i = 0; i < p.size(); i++) { 
        auto f = letters.find(p[i]);
        if (f != letters.end()) { 
            f->second.first++;
            f->second.second++;
        }
        else { 
            letters.insert({p[i], {1, 1}});
        }
    }
    for (auto itr = letters.begin(); itr != letters.end(); itr++) { 
        std::cout << itr->first << " " << itr->second.first << std::endl;
    }
    for (int i = 0; i < p.size(); i++) { 
        for (unsigned int j = 0; j < s.size(); j++) { 
            auto f = letters.find(s[j]);
            if (f == letters.end()) { 
                std::cout << j << " " << i << " " << s[j] << " NULL" << std::endl;
            }
            else 
            std::cout << j << " " << i << " " << s[j] << " " << f->first << " " << f->second.first << std::endl;
            if (f == letters.end() || f->second.first == 0) { 
                revert(letters);
                break;
                std::cout << "1" << std::endl;
            }
            if (i == p.size() - 1) { 
                answer.push_back(j);
                revert(letters); 
                std::cout << "3" << std::endl;
            }
            f->second.first--;           
        }
    }
    return answer;
}

int main() { 
    vector<int> a = findAnagrams("cbaebabacd", "abc");
    for (int i = 0; i < a.size(); i++) { 
        cout << a[i] << " ";
    }
}