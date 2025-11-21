#include <stdio.h>

int main() {
    int n, e;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    // Initialize adjacency matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // For an undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;

        // For a directed graph, use only:
        // adj[u][v] = 1;
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
