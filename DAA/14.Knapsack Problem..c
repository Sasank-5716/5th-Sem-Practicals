#include <stdio.h>
#include <stdlib.h>

// Title: 0/1 Knapsack Problem using Dynamic Programming

// Theory:
// The 0/1 Knapsack Problem involves selecting items with given weights and values to maximize total value
// without exceeding a maximum weight capacity. Dynamic programming is used to solve this optimization problem
// by breaking it into smaller subproblems and storing results in a table.

// Algorithm:
// 1. Create a DP table (rows = items, columns = weights)
// 2. Initialize base case (0 items = 0 value)
// 3. Fill table using optimal substructure property:
//    - If current item's weight <= current capacity: max(value with item, value without item)
//    - Else: carry forward previous value
// 4. Traceback to find selected items
// Time Complexity: O(n*W), Space Complexity: O(n*W)

int max(int a, int b) { return (a > b) ? a : b; }

void knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Build DP table
    for(int i=0; i<=n; i++) {
        for(int w=0; w<=W; w++) {
            if(i==0 || w==0) dp[i][w] = 0;
            else if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    // Display results
    printf("Maximum value: %d\n", dp[n][W]);

    // Item selection traceback
    printf("Selected items: ");
    int w = W;
    for(int i=n; i>0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            printf("%d ", i-1);
            w -= wt[i-1];
        }
    }
}

int main() {
    printf("Sasank Lama \n");

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);

    knapsack(W, wt, val, n);
    return 0;
}

// Conclusion:
// Dynamic Programming efficiently solves the 0/1 Knapsack Problem by avoiding redundant calculations.
// The solution demonstrates optimal substructure and overlapping subproblems properties.
// Time complexity is pseudo-polynomial (O(n*W)), making it suitable for reasonable weight capacities.
