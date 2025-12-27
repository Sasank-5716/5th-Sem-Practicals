#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        // Variable to check if swapping occurred
        int swapped = 0;

        // Compare adjacent elements
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                // Swap if elements are in the wrong order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        // If no swapping occurred, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    printf("Sasank Lama \n");
    int data[] = {64, 34, 25, 12, 22, 11, 90}; // Example array
    int size = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array:\n");
    printArray(data, size);

    bubbleSort(data, size);

    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);

    return 0;
}
