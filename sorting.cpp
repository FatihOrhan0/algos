#include <iostream>
#include <vector>

template <class T>
void print(std::vector<T> & vec) { 
    for (unsigned int i = 0; i < vec.size(); i++) { 
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void quickSort(std::vector<T> & vec, int low, int high) { 
    if (low >= high) { return; }
    int pivot = high;
    int start = low;
    for (int i = low; i < high; i++) { 
        if (vec[i] < vec[pivot]) { 
            T temp = vec[start];
            vec[start] = vec[low];
            vec[low] = temp;
            start++;
        }
    }
    T temp = vec[pivot];
    vec[pivot] = vec[start];
    vec[start] = temp;
    print(vec);
    quickSort(vec, low, start - 1);
    quickSort(vec, start + 1, high);
}
//driver function for quicksort: 
template <class T>
void quickSort(std::vector<T> & vec) { 
    quickSort(vec, 0, vec.size() - 1);
}

int main() { 
    //quicksort test:
   /*  std::vector<int> nums(200);
    for (int i = 0; i < 200; i++) { 
        nums[i] = 200 - i;
    }
    print(nums);
    std::cout << "sorted:" << std::endl;
    quickSort<int>(nums);
    print(nums); */
    std::vector<int> nums2 = {3, 7, 1, 8, 4, 11, 20, 5};
    print(nums2);
    quickSort(nums2);
    print(nums2);
}