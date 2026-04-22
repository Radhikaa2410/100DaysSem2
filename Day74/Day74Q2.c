#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int **g, int n, int u, bool *vis){
    for(int i = 0; i < n; i++){
        if(g[u][i] == 1 && !vis[i]){
            vis[i] = true;
            dfs(g, n, i, vis);
        }
    }
}

int prov(int **g, int n){
    bool *vis = (bool*)malloc(n * sizeof(bool));

    for(int i = 0; i < n; i++)
        vis[i] = false;

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(g, n, i, vis);
            cnt++;
        }
    }

    free(vis);
    return cnt;
}

int main(){
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int **g = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        g[i] = (int*)malloc(n * sizeof(int));

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &g[i][j]);
        }
    }

    printf("Number of Provinces: %d\n", prov(g, n));

    for(int i = 0; i < n; i++)
        free(g[i]);
    free(g);

    return 0;
}