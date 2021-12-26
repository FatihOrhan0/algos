#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <iostream>

using namespace std;

vector<int> findSubstring(string s, vector<string> & words) {
    vector<int> results;
    unordered_map<string, pair<int, int> > hs;
    unsigned int wordLength = words[0].size();
    //adding the words to the hash table
    for (unsigned int i = 0; i < words.size(); i++) { 
        if (hs.find(words[i]) == hs.end()) { 
            hs.insert({words[i], make_pair(1, 1)});
        }
        else { 
            auto val = hs.find(words[i]);
            val->second.first++; val->second.second++;
        }
    }

    for (unsigned int i = 0; i < s.size() - wordLength + 1; i++) { 
        int count = 0;
        string cur = s.substr(i, wordLength);
        auto pos = hs.find(cur);
        unsigned int curIndex = i;
        if (pos == hs.end()) continue;
        else { 
            while (pos != hs.end() && count < words.size()) { 
                pos->second.first--;
                if (pos->second.first == -1) { 
                    count = 0;
                    break;
                }
                count++;
                curIndex += wordLength;
                cur = s.substr(curIndex, wordLength);
                pos = hs.find(cur);
            }
            if (count == words.size()) { 
                results.push_back(i);
            }
            for (auto itr = hs.begin(); itr != hs.end(); itr++) { 
                itr->second.first = itr->second.second;
            }
        }
    }
    return results;
}

int main() { 
    vector<string> words = {"bar", "foo", "the"};
    vector<int> res = findSubstring("barfoofoobarthefoobarman", words);
    for (int i = 0; i < res.size(); i++) { 
        std::cout << res[i] << " ";
    }
    std::cout << "size of res: " << res.size(); 
}