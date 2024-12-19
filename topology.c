#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int V; // Number of vertices

// Function to perform DFS and push the vertex to stack after visiting all its neighbors
void dfs(int v) {
    visited[v] = 1; // Mark the current node as visited

    // Visit all adjacent vertices
    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    // Push the current vertex to the stack
    stack[++top] = v;
}

// Function to perform Topological Sort using DFS
void topologicalSort() {
    // Initialize visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Perform DFS for every vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order (reverse of the stack)
    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// Main function
int main() {
    // Read number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize adjacency matrix
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Perform topological sort
    topologicalSort();

    return 0;
}

