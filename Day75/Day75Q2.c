#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool bip(int **g, int n, int *sz){
    int *col = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        col[i] = -1;

    for(int i = 0; i < n; i++){
        if(col[i] != -1) continue;

        int *q = (int*)malloc(n * sizeof(int));
        int f = 0, r = 0;

        q[r++] = i;
        col[i] = 0;

        while(f < r){
            int u = q[f++];

            for(int j = 0; j < sz[u]; j++){
                int v = g[u][j];

                if(col[v] == -1){
                    col[v] = 1 - col[u];
                    q[r++] = v;
                }
                else if(col[v] == col[u]){
                    free(q);
                    free(col);
                    return false;
                }
            }
        }
        free(q);
    }

    free(col);
    return true;
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int **g = (int**)malloc(n * sizeof(int*));
    int *sz = (int*)malloc(n * sizeof(int));

    printf("Enter number of neighbors for each node:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &sz[i]);
        g[i] = (int*)malloc(sz[i] * sizeof(int));
    }

    printf("Enter adjacency list:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < sz[i]; j++){
            scanf("%d", &g[i][j]);
        }
    }

    if(bip(g, n, sz))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    for(int i = 0; i < n; i++)
        free(g[i]);
    free(g);
    free(sz);

    return 0;
}