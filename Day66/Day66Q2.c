#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DFS for cycle detection
bool dfs(int node, int** adj, int* sz, int* state) {
    if (state[node] == 1) return true;   // cycle
    if (state[node] == 2) return false;  // already processed

    state[node] = 1;

    for (int i = 0; i < sz[node]; i++) {
        int next = adj[node][i];
        if (dfs(next, adj, sz, state))
            return true;
    }

    state[node] = 2;
    return false;
}

// Main function logic
bool canFinish(int n, int** pre, int ps) {

    int** adj = (int**)malloc(n * sizeof(int*));
    int* sz = (int*)calloc(n, sizeof(int));

    // Count sizes
    for (int i = 0; i < ps; i++)
        sz[pre[i][1]]++;

    // Allocate
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(sz[i] * sizeof(int));
        sz[i] = 0;
    }

    // Fill graph
    for (int i = 0; i < ps; i++) {
        int a = pre[i][0];
        int b = pre[i][1];
        adj[b][sz[b]++] = a;
    }

    int* state = (int*)calloc(n, sizeof(int));

    // Check cycle
    for (int i = 0; i < n; i++) {
        if (dfs(i, adj, sz, state)) {
            free(state);
            for (int j = 0; j < n; j++) free(adj[j]);
            free(adj);
            free(sz);
            return false;
        }
    }

    // Free memory
    free(state);
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(sz);

    return true;
}

// Main
int main() {
    int n, p;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    printf("Enter number of prerequisites: ");
    scanf("%d", &p);

    int** pre = (int**)malloc(p * sizeof(int*));

    printf("Enter prerequisites (a b):\n");
    for (int i = 0; i < p; i++) {
        pre[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &pre[i][0], &pre[i][1]);
    }

    if (canFinish(n, pre, p))
        printf("true\n");
    else
        printf("false\n");

    // Free input
    for (int i = 0; i < p; i++) free(pre[i]);
    free(pre);

    return 0;
}