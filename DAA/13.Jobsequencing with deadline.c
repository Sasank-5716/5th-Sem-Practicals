#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Title: Job Sequencing with Deadlines using Greedy Algorithm

// Theory:
// Job Sequencing with Deadlines is a scheduling problem where jobs are assigned to maximize profit within given deadlines.
// Each job has a deadline and a profit, and the goal is to schedule jobs such that the total profit is maximized.
// The Greedy algorithm sorts jobs by profit in descending order and schedules them within their deadlines.

struct Job {
    char id;       // Job ID
    int deadline;  // Deadline of the job
    int profit;    // Profit of the job
};

// Comparison function to sort jobs by profit in descending order
int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Algorithm:
// 1. Sort jobs by profit in descending order.
// 2. Initialize an array to track free time slots.
// 3. Schedule jobs in the latest available slot before their deadline.
// 4. Print the scheduled jobs and their total profit.

void jobSequencing(struct Job jobs[], int n) {
    // Step 1: Sort jobs by profit
    qsort(jobs, n, sizeof(struct Job), compare);

    int result[n];   // To store the sequence of jobs
    bool slot[n];    // To track free time slots
    for (int i = 0; i < n; i++) slot[i] = false;

    int totalProfit = 0;

    // Step 2: Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Step 3: Print scheduled jobs and total profit
    printf("Scheduled Jobs:\n");
    printf("-----------------------------\n");
    printf("| Job | Deadline | Profit |\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("| %c   | %d       | %d     |\n", jobs[result[i]].id, jobs[result[i]].deadline, jobs[result[i]].profit);
        }
    }
    printf("-----------------------------\n");
    printf("Total Profit: %d\n", totalProfit);
}

// Main function
int main() {
    printf("Sasank Lama \n");
    struct Job jobs[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}

// Conclusion:
// The Greedy algorithm effectively schedules jobs to maximize profit within deadlines.
// Time complexity: O(n log n) due to sorting.
// Space complexity: O(n) for tracking slots.
