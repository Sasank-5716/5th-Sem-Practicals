#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

// Comparator function for sorting items by value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio;
    double r2 = ((Item *)b)->ratio;
    return (r1 < r2) ? 1 : -1;
}

// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items by ratio
    double totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity; // Add fraction of item
            break;
        }
    }
    return totalValue;
}

int main() {
    printf("Sasank Lama \n");
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in knapsack: %.2f\n", maxValue);

    return 0;
}
