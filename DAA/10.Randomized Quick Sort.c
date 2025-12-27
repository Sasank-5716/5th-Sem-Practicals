#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using a random pivot
int randomizedPartition(int arr[], int low, int high) {
    // Generate a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]); // Swap random pivot with last element

    int pivot = arr[high]; // Pivot element
    int i = low - 1;       // Index for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return i + 1;                 // Return pivot index
}

// Function to perform Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high); // Partition index

        // Recursively sort elements before and after partition
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Sasank Lama \n");
    srand(time(0)); // Seed for random number generation

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    randomizedQuickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
