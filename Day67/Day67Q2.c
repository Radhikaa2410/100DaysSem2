#include <stdio.h>
#include <stdlib.h>

// Function
int* findOrder(int n, int** pre, int ps, int* pcs, int* rs) {
    
    int** g = (int**)malloc(n * sizeof(int*));
    int* sz = (int*)calloc(n, sizeof(int));

    // Allocate max space
    for (int i = 0; i < n; i++)
        g[i] = (int*)malloc(n * sizeof(int));

    int* indeg = (int*)calloc(n, sizeof(int));

    // Build graph
    for (int i = 0; i < ps; i++) {
        int a = pre[i][0];
        int b = pre[i][1];
        g[b][sz[b]++] = a;
        indeg[a]++;
    }

    // Queue
    int* q = (int*)malloc(n * sizeof(int));
    int f = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            q[r++] = i;
    }

    int* res = (int*)malloc(n * sizeof(int));
    int cnt = 0;

    while (f < r) {
        int node = q[f++];
        res[cnt++] = node;

        for (int i = 0; i < sz[node]; i++) {
            int nei = g[node][i];
            indeg[nei]--;
            if (indeg[nei] == 0)
                q[r++] = nei;
        }
    }

    // Cycle case
    if (cnt != n) {
        *rs = 0;
        return NULL;
    }

    *rs = n;
    return res;
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

    int rs;
    int* order = findOrder(n, pre, p, NULL, &rs);

    if (rs == 0) {
        printf("[]\n");
    } else {
        printf("Order: ");
        for (int i = 0; i < rs; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < p; i++) free(pre[i]);
    free(pre);

    return 0;
}