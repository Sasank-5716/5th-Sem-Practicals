#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    printf("Sasank Lama \n");
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    // Iterative Approach
    int result = binarySearchIterative(arr, size, target);
    printf("Iterative: Target %d found at index %d\n", target, result);

    // Recursive Approach
    result = binarySearchRecursive(arr, 0, size - 1, target);
    printf("Recursive: Target %d found at index %d\n", target, result);

    return 0;
}
