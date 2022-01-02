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
void bubbleSort(std::vector<T> & vec) { 
    for (unsigned int i = 0; i < vec.size(); i++) { 
        for (unsigned int j = 0; j < vec.size() - 1; j++) { 
            if (vec[j] > vec[j + 1]) { 
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template <class T> 
void insertionSort(std::vector<T> & vec) { 
    for (unsigned int i = 0; i < vec.size() - 1; i++) { 
        unsigned int j = i + 1;
        while (j > 0) {
            if (vec[j] < vec[j - 1]) { 
                std::swap(vec[j], vec[j - 1]);
                j--;
            }
            else { 
                break;
            }
        }
    }
}

template <class T> 
void selectionSort(std::vector<T> & vec) { 
    for (unsigned int start = 0; start < vec.size(); start++) {
        int min = vec[start];
        int minIndex = start;   
        for (unsigned int i = start; i < vec.size(); i++) { 
            if (vec[i] < min) {
                min = vec[i];
                minIndex = i;
            }
        }
        std::swap(vec[minIndex], vec[start]);
    }
}

template <class T>
void quickSort(std::vector<T> & vec, int low, int high) { 
    if (low >= high) { return; }
    int start = low;
    for (int i = low; i < high; i++) { 
        if (vec[i] <= vec[high]) { 
            std::swap(vec[start], vec[i]);
            start++;
        }
    }
    std::swap(vec[start], vec[high]);
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
    selectionSort(nums2);
    print(nums2);
}