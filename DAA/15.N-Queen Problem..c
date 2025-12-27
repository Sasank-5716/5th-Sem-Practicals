#include <stdio.h>
#include <stdbool.h>

#define N 4 // Change this value for different board sizes

// Title: N-Queen Problem using Backtracking Algorithm

// Theory:
// The N-Queen Problem is a classic example of constraint satisfaction problems solved using backtracking.
// The goal is to place N queens on an NxN chessboard such that no two queens threaten each other.
// A queen can attack horizontally, vertically, or diagonally.
// Backtracking systematically explores all possible configurations and prunes invalid paths.

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }

    return true;
}

// Backtracking function to solve the N-Queen problem
bool solveNQueen(int board[N][N], int row) {
    // Base case: If all queens are placed, return true
    if (row >= N) return true;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively place the rest of the queens
            if (solveNQueen(board, row + 1)) return true;

            // Backtrack: Remove the queen and try another position
            board[row][col] = 0;
        }
    }

    // If no position is valid, return false
    return false;
}

int main() {
    printf("Sasank Lama \n");
    int board[N][N] = {0};

    if (solveNQueen(board, 0)) {
        printf("Solution:\n");
        printSolution(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

// Conclusion:
// The backtracking algorithm efficiently solves the N-Queen problem by exploring all possible configurations.
// It uses pruning to eliminate invalid paths early, reducing unnecessary computations.
// Time complexity: O(N!), Space complexity: O(N^2) due to the chessboard representation.
