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
    for (unsigned int j = 0; j < s.size(); j++) { 
        int c = j;
        for (int i = 0; i < p.size(); i++, c++) { 
            if (c >= s.size()) { return answer; }
            auto f = letters.find(s[c]);
            if (f == letters.end() || f->second.first == 0) { 
                break;
            }
            if (i == p.size() - 1) { 
                answer.push_back(j); 
            }
            f->second.first--;           
        }
        revert(letters);
    }
    return answer;
}

int main() { 
    vector<int> a = findAnagrams("kemal", "kemale");
    for (int i = 0; i < a.size(); i++) { 
        cout << a[i] << " ";
    }
}