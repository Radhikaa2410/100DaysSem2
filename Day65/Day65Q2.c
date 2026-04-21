#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Find with path compression
int find(int p[], int x) {
    if (p[x] != x)
        p[x] = find(p, p[x]);
    return p[x];
}

// Union
void unionSet(int p[], int x, int y) {
    int px = find(p, x);
    int py = find(p, y);
    p[px] = py;
}

// Cycle detection
bool isCycle(int e[][2], int E, int V) {
    int *p = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        p[i] = i;

    for (int i = 0; i < E; i++) {
        int u = e[i][0];
        int v = e[i][1];

        int pu = find(p, u);
        int pv = find(p, v);

        if (pu == pv) {
            free(p);
            return true;
        }

        unionSet(p, pu, pv);
    }

    free(p);
    return false;
}

// Main
int main() {
    int V, E;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    int e[E][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &e[i][0], &e[i][1]);
    }

    if (isCycle(e, E, V))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}