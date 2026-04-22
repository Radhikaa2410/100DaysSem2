#include <stdio.h>
#include <stdlib.h>

int t = 0;

void dfs(int u, int p, int *d, int *l,
         int **g, int *sz,
         int **res, int *rs, int *cs){

    d[u] = l[u] = ++t;

    for(int i = 0; i < sz[u]; i++){
        int v = g[u][i];

        if(v == p) continue;

        if(d[v] == -1){
            dfs(v, u, d, l, g, sz, res, rs, cs);

            l[u] = l[u] < l[v] ? l[u] : l[v];

            if(l[v] > d[u]){
                res[*rs] = (int*)malloc(2 * sizeof(int));
                res[*rs][0] = u;
                res[*rs][1] = v;
                cs[*rs] = 2;
                (*rs)++;
            }
        }
        else{
            l[u] = l[u] < d[v] ? l[u] : d[v];
        }
    }
}

int main(){
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int **edges = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        edges[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++){
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int *sz = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < m; i++){
        sz[edges[i][0]]++;
        sz[edges[i][1]]++;
    }

    int **g = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        g[i] = (int*)malloc(sz[i] * sizeof(int));
        sz[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int u = edges[i][0], v = edges[i][1];
        g[u][sz[u]++] = v;
        g[v][sz[v]++] = u;
    }

    int *d = (int*)malloc(n * sizeof(int));
    int *l = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        d[i] = -1;
        l[i] = -1;
    }

    int **res = (int**)malloc(m * sizeof(int*));
    int *cs = (int*)malloc(m * sizeof(int));
    int rs = 0;

    for(int i = 0; i < n; i++){
        if(d[i] == -1)
            dfs(i, -1, d, l, g, sz, res, &rs, cs);
    }

    printf("Critical Connections:\n");
    for(int i = 0; i < rs; i++){
        printf("[%d, %d]\n", res[i][0], res[i][1]);
    }

    return 0;
}