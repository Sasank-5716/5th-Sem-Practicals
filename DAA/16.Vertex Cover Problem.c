#include <stdio.h>
#include <stdbool.h>

// Title: Vertex Cover Problem using Approximation Algorithm

// Theory:
// The Vertex Cover Problem is a classical NP-hard problem in graph theory. A vertex cover is a set of vertices such that
// every edge in the graph is incident to at least one vertex in the set. The goal is to find the minimum vertex cover.
// Since finding the exact solution is computationally infeasible for large graphs, approximation algorithms are used.
// The 2-approximation algorithm guarantees that the size of the vertex cover is at most twice the optimal size.
// It works by constructing a maximal matching and including both endpoints of each edge in the matching as part of the vertex cover.

// Algorithm:
// 1. Initialize the vertex cover set as empty.
// 2. While there are uncovered edges in the graph:
//    - Pick an arbitrary edge (u, v).
//    - Add both u and v to the vertex cover.
//    - Remove all edges incident to u or v from consideration.
// 3. Return the vertex cover set.

#define MAX 100 // Maximum number of vertices

void vertexCoverApproximation(int n, int graph[MAX][MAX]) {
    bool visited[MAX] = {0}; // Track visited vertices
    printf("Approximate Vertex Cover:\n");

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[u] && !visited[v]) {
                // Include both endpoints in the vertex cover
                printf("%d %d\n", u, v);
                visited[u] = true;
                visited[v] = true;

                // Remove all edges incident to u and v
                for (int i = 0; i < n; i++) {
                    graph[u][i] = 0;
                    graph[v][i] = 0;
                    graph[i][u] = 0;
                    graph[i][v] = 0;
                }
            }
        }
    }
}

int main() {
    printf("Sasank Lama \n");
    int n = 6; // Number of vertices
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    vertexCoverApproximation(n, graph);
    return 0;
}

// Conclusion:
// The approximation algorithm for the Vertex Cover Problem provides an efficient solution with a guaranteed approximation ratio of at most two.
// This approach constructs a maximal matching and includes both endpoints of each edge in the matching as part of the vertex cover.
// Time complexity: O(V^2) for dense graphs due to edge traversal.
// Space complexity: O(V^2) for adjacency matrix representation.
