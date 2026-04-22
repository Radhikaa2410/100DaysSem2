#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int t = 0;

void dfs(int u, int p, int *vis, int *d, int *l,
         int **g, int *sz, int *ap){

    vis[u] = 1;
    d[u] = l[u] = ++t;

    int ch = 0;

    for(int i = 0; i < sz[u]; i++){
        int v = g[u][i];

        if(v == p) continue;

        if(!vis[v]){
            ch++;
            dfs(v, u, vis, d, l, g, sz, ap);

            l[u] = l[u] < l[v] ? l[u] : l[v];

            if(p != -1 && l[v] >= d[u])
                ap[u] = 1;
        }
        else{
            l[u] = l[u] < d[v] ? l[u] : d[v];
        }
    }

    if(p == -1 && ch > 1)
        ap[u] = 1;
}

int main(){
    int V, E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    int **g = (int**)malloc(V * sizeof(int*));
    int *sz = (int*)calloc(V, sizeof(int));

    int **edges = (int**)malloc(E * sizeof(int*));
    for(int i = 0; i < E; i++){
        edges[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter edges:\n");
    for(int i = 0; i < E; i++){
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        sz[edges[i][0]]++;
        sz[edges[i][1]]++;
    }

    for(int i = 0; i < V; i++){
        g[i] = (int*)malloc(sz[i] * sizeof(int));
        sz[i] = 0;
    }

    for(int i = 0; i < E; i++){
        int u = edges[i][0], v = edges[i][1];
        g[u][sz[u]++] = v;
        g[v][sz[v]++] = u;
    }

    int *vis = (int*)calloc(V, sizeof(int));
    int *d = (int*)malloc(V * sizeof(int));
    int *l = (int*)malloc(V * sizeof(int));
    int *ap = (int*)calloc(V, sizeof(int));

    for(int i = 0; i < V; i++){
        if(!vis[i])
            dfs(i, -1, vis, d, l, g, sz, ap);
    }

    int found = 0;
    printf("Articulation Points: ");
    for(int i = 0; i < V; i++){
        if(ap[i]){
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found) printf("-1");

    return 0;
}