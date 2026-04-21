#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int* topoSort(int V, int adj[MAX][MAX], int* returnSize) {
    int indegree[MAX] = {0};

    // Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                indegree[j]++;
            }
        }
    }

    int q[MAX];
    int f = 0, r = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q[r++] = i;
        }
    }

    int* res = (int*)malloc(V * sizeof(int));
    int cnt = 0;

    while (f < r) {
        int node = q[f++];
        res[cnt++] = node;

        for (int j = 0; j < V; j++) {
            if (adj[node][j]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    q[r++] = j;
                }
            }
        }
    }

    // Cycle check
    if (cnt != V) {
        *returnSize = 0;
        free(res);
        return NULL;
    }

    *returnSize = cnt;
    return res;
}

// Main
int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int size;
    int* order = topoSort(V, adj, &size);

    if (order == NULL) {
        printf("Cycle detected! No topological ordering.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
        free(order);
    }

    return 0;
}