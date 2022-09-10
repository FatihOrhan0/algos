from typing import List

def binarySearch(arr: List[int], target: int) -> int:
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return -1




arr = [1,2,3,4,5,6]
loc = binarySearch(arr, -6)
print(loc)

def main():
    print(loc)


if __name__ == "__main__":
    main()