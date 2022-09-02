// Problem: find the length of the longest contiguous subarray after at most k removals from an array

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int parseIntervals(vector<pair<int, int> > & hash, int k) { 
    int left = 0;
    int right = 0;
    int temp = k;
    int ans = hash[right].second - hash[right].first + 1;
    int max = ans;
    while (right < hash.size() - 1) {
        int diff = hash[right + 1].first - hash[right].second - 1;
        if (k >= diff) { 
            k -= diff;
            right++;
            ans += hash[right].second - hash[right].first + 1;
            max = std::max(ans, max);
        }
        else { 
            while (left != right and k < diff) { 
                ans -= hash[left].second - hash[left].first + 1;
                k += hash[left + 1].first - hash[left].second - 1;
                left++;
            }
            if (left == right) { 
                k = temp;
                right++;
                left++;
                ans = hash[right].second - hash[right].first + 1;
                max = std::max(ans, max);
            }
        }
    }
    return max;
}

int kIndex(const vector<int> & vec, int k) { 
    if (vec.size() < 2) return 1;
    unordered_map<int, vector<pair<int, int> > > hash;
    int pos = 1;
    if (vec[0] == vec[1]) { 
        while (pos < vec.size() && vec[pos] == vec[pos - 1]) {
            pos++;
        }
        hash[vec[0]].push_back({0, pos - 1});
    }
    else { 
        hash[vec[0]].push_back({0, 0});
    }
    for (; pos < vec.size(); pos++) { 
        if (pos + 1 < vec.size() && vec[pos + 1] == vec[pos]) { 
            int temp = pos;
            while (pos + 1 < vec.size() && vec[pos + 1] == vec[pos]) { 
                pos++;   
            }
            hash[vec[temp]].push_back({temp, pos});
        }
        else { 
            hash[vec[pos]].push_back({pos, pos});
        }
    }
    /* for (auto itr : hash) { 
        cout << "first: " << itr.first << endl;
        for (auto itr2 : itr.second) { 
            cout << itr2.first << " " << itr2.second << endl;
        }
        cout << endl;
    } */
    int ans = 1;
    for (auto itr : hash) { 
        ans = max(parseIntervals(itr.second, k), ans);
    }
    return ans;
}




int main() {
    vector<int> vec = {1, 1, 2, 1, 1, 3, 3, 3, 3, 1, 1, 1};
    cout << "ans: " << kIndex(vec, 3);
    return 0;
}