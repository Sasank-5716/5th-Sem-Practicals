#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (similar to Quick Sort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose last element as pivot
    int i = low - 1;       // Index for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If current element is smaller than pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return i + 1;                 // Return pivot index
}

// Randomized Partition function
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // Randomly select pivot
    swap(&arr[randomIndex], &arr[high]);              // Swap with last element
    return partition(arr, low, high);
}

// Function to find the k-th smallest element using Divide and Conquer
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = randomizedPartition(arr, low, high);

        // If pivot index matches k, return the element at pivot index
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex > k - 1) { // Search in left subarray
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else { // Search in right subarray
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    return -1; // Return -1 if k is out of bounds
}

int main() {
    printf("Sasank Lama \n ");
    srand(time(0)); // Seed for random number generation

    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 3rd smallest element

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = quickSelect(arr, 0, size - 1, k);
    printf("The %d-th smallest element is %d\n", k, result);

    return 0;
}
