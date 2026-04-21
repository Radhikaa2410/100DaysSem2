#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DFS function
void dfs(int** isConnected, int n, int city, bool* visited) {
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(isConnected, n, i, visited);
        }
    }
}

// Function to find number of provinces
int findCircleNum(int** isConnected, int n) {
    bool visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(isConnected, n, i, visited);
            provinces++;
        }
    }

    return provinces;
}

// Main function
int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Allocate memory for matrix
    int** isConnected = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        isConnected[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findCircleNum(isConnected, n);

    printf("Number of provinces: %d\n", result);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(isConnected[i]);
    }
    free(isConnected);

    return 0;
}