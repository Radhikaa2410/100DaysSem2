#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int networkDelayTime(int** times, int ts, int n, int k) {
    int** g = (int**)malloc((n + 1) * sizeof(int*));

    for (int i = 0; i <= n; i++) {
        g[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++)
            g[i][j] = INT_MAX;
    }

    // Build graph
    for (int i = 0; i < ts; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        g[u][v] = w;
    }

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    int* vis = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }

    dist[k] = 0;

    // Dijkstra (O(n^2))
    for (int i = 1; i <= n; i++) {
        int u = -1, mn = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < mn) {
                mn = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        vis[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (g[u][v] != INT_MAX && dist[u] != INT_MAX) {
                if (dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > ans)
            ans = dist[i];
    }

    return ans;
}

// Main
int main() {
    int n, e;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    int** times = (int**)malloc(e * sizeof(int*));

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        times[i] = (int*)malloc(3 * sizeof(int));
        scanf("%d %d %d", &times[i][0], &times[i][1], &times[i][2]);
    }

    int k;
    printf("Enter source node: ");
    scanf("%d", &k);

    int res = networkDelayTime(times, e, n, k);

    printf("Output: %d\n", res);

    // Free memory
    for (int i = 0; i < e; i++) free(times[i]);
    free(times);

    return 0;
}