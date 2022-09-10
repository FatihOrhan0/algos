#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
    int total = nums1.size() + nums2.size();
    int start = 0, end = nums1.size() - 1;
    while (1) { 
        int i = (start + end) / 2;
        int j = total / 2 - i - 2;
        int right1 = 0, right2  = 0, left1 = 0, left2 = 0;
        if (i + 1 >= nums1.size()) right1 = INT_MAX;
        else { left1 = nums1[i + 1]; }
        if (j + 1 >= nums2.size()) right2 = INT_MAX;
        else { right2 = nums2[j + 1]; }
        if (j >= 0) left1 = nums2[j];
        else { left1 = INT_MIN; }
        if (i >= 0) left2 = nums1[i];
        else left2 = INT_MIN;
        cout << i << " " << j << endl;
        
        
        if (left1 <= right2 && left1 <= right1) { 
            if (total % 2 == 1) return std::min(right1, right2);
            else return ((float) std::max(left1, left2)) + (float) std::min(right1, right2) / 2;
        }
        else if (left2> right2) { 
            end = i - 1;
        }
        else { 
            start = i + 1;
        }
    }
        
}

int main() { 
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 1;
}