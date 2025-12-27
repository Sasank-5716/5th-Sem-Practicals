#include <stdio.h>

// Function to perform sequential search
int sequentialSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to print array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    printf("Sasank Lama \n");
    int data[] = {10, 20, 30, 40, 50};  // Example array
    int size = sizeof(data) / sizeof(data[0]);
    int target;  // Element to search
    scanf("%d", &target);

    printf("Array elements:\n");
    printArray(data, size);

    int result = sequentialSearch(data, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
