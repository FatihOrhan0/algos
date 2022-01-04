#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

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

template <class T> 
std::vector<T> merge(const std::vector<T> & vec1, std::vector<T> & vec2) { 
    std::vector<T> combined(vec1.size() + vec2.size());
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int index = 0;
    while (i < vec1.size() && j < vec2.size()) { 
        if (vec1[i] < vec2[j]) { 
            combined[index] = vec1[i];
            i++; index++;
        }
        else { 
            combined[index] = vec2[j];
            j++; index++;
        }
    } 
    for (; i < vec1.size(); i++) { 
        combined[index] = vec1[i];
        index++;
    }
    for (; j < vec2.size(); j++) { 
        combined[index] = vec2[j];
        index++;
    }
    return combined;
}

template <class T> 
void mergeSort(std::vector<T> & vec) { 
    if (vec.size() < 2) { 
        return;
    }
    else { 
        std::vector<T> first;
        std::vector<T> second;
        for (unsigned int i = 0; i < vec.size() / 2; i++) { 
            first.push_back(vec[i]);
        }
        for (unsigned int i = vec.size() / 2; i < vec.size(); i++) { 
            second.push_back(vec[i]);
        }
        mergeSort(first);
        mergeSort(second);
        vec = merge(first, second);
    }
    
}

unsigned int leftChild(unsigned int i) { 
    return 2 * i + 1;
}

unsigned int rightChild(unsigned int i) { 
    return 2 * i + 2;
}

template <class T> 
void heapifySingle(std::vector<T> & vec, unsigned int i) { 
    T min = vec[i];
    bool right = false;
    if (vec[leftChild(i)] < vec[i] && leftChild(i) < vec.size()) { 
        min = vec[leftChild(i)];
    }
    if (vec[rightChild(i)] < min && rightChild(i) < vec.size()) { 
        min = vec[rightChild(i)];
        right = true;
    }
    if (min < vec[i] && !right) { 
        std::swap(vec[i], vec[leftChild(i)]);
    }
    else if (min < vec[i] && right) { 
        std::swap(vec[i], vec[rightChild(i)]);
    }
}

template <class T> 
void heapify(std::vector<T> & vec) { 
    for (unsigned int i = vec.size() / 2; i > 0; i--) { 
        heapifySingle(vec, i);
    }
}

template <class T> 
void heapSort(std::vector<T> & vec) { 
    
}

int main() { 
    std::vector<int> smaller = {1, 6, 8, 11, 20, 31, 55};
    std::vector<int> greater = {3, 7, 24, 45, 87, 102, 126};
    std::vector<int> combined = merge(smaller, greater);
    print(combined);

    shuffle(combined.begin(), combined.end(), std::default_random_engine());
    print(combined);
    mergeSort(combined);
    print(combined);
}