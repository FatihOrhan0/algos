#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> findOriginalArray(vector<int> & changed) {
    if (changed.size() % 2 == 1) return vector<int>();
    unordered_map<int, int> hash;
    sort(changed.begin(), changed.end());
    for (int i = 0; i < changed.size(); i++) { 
        if (hash.find(changed[i]) == hash.end()) { 
            hash.insert({changed[i], 1});
        }
        else hash.find(changed[i])->second++;
    }
    vector<int> original;
    for (int i = 0; i < changed.size(); i++) { 
        unordered_map<int, int>::iterator itr2 = hash.find(changed[i]);
        if (itr2->second == 0) continue;
        unordered_map<int, int>::iterator itr = hash.find(changed[i] * 2);
        if (itr == hash.end()) {
            return vector<int>();
        }
        if (itr->second == 0) {
            return vector<int>();
        }
        itr2->second--;
        itr->second--;
        original.push_back(changed[i]);
    }
    return original;
}


int main() {
    vector<int> temp = {1, 3, 4, 2, 6, 8};
    vector<int> temp2 = findOriginalArray(temp);
    for (int i : temp2) { 
        cout << i << endl;
    }
    return EXIT_SUCCESS;
}