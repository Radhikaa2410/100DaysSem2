#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function
int findCheapestPrice(int n, int** f, int fs, int src, int dst, int k) {
    int* dist = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges k+1 times
    for (int i = 0; i <= k; i++) {
        int* temp = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < fs; j++) {
            int u = f[j][0];
            int v = f[j][1];
            int w = f[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];

        free(temp);
    }

    int ans = dist[dst];
    free(dist);

    return (ans == INT_MAX) ? -1 : ans;
}

// Main
int main() {
    int n, e;

    printf("Enter number of cities and flights: ");
    scanf("%d %d", &n, &e);

    int** f = (int**)malloc(e * sizeof(int*));

    printf("Enter flights (u v cost):\n");
    for (int i = 0; i < e; i++) {
        f[i] = (int*)malloc(3 * sizeof(int));
        scanf("%d %d %d", &f[i][0], &f[i][1], &f[i][2]);
    }

    int src, dst, k;
    printf("Enter src, dst, k: ");
    scanf("%d %d %d", &src, &dst, &k);

    int res = findCheapestPrice(n, f, e, src, dst, k);

    printf("Output: %d\n", res);

    // Free memory
    for (int i = 0; i < e; i++) free(f[i]);
    free(f);

    return 0;
}