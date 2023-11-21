#include <stdio.h>

// Linear search function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

// Binary search function (assuming the array is sorted)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found, return its index
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 7, 11, 13, 16, 19, 23, 29, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 16;

    // Linear Search
    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1) {
        printf("Linear Search: Element %d found at index %d\n", target, linearResult);
    } else {
        printf("Linear Search: Element %d not found\n", target);
    }

    // Binary Search
    int binaryResult = binarySearch(arr, 0, n - 1, target);
    if (binaryResult != -1) {
        printf("Binary Search: Element %d found at index %d\n", target, binaryResult);
    } else {
        printf("Binary Search: Element %d not found\n", target);
    }

    return 0;
}

