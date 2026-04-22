#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// stack
int st[MAX], top = -1;

void push(int x){ st[++top] = x; }
int pop(){ return st[top--]; }
int empty(){ return top == -1; }

// DFS 1 (fill stack)
void dfs1(int u, int **g, int *sz, int *vis){
    vis[u] = 1;

    for(int i = 0; i < sz[u]; i++){
        int v = g[u][i];
        if(!vis[v])
            dfs1(v, g, sz, vis);
    }

    push(u);
}

// DFS 2 (on reversed graph)
void dfs2(int u, int **gt, int *sz, int *vis){
    vis[u] = 1;

    for(int i = 0; i < sz[u]; i++){
        int v = gt[u][i];
        if(!vis[v])
            dfs2(v, gt, sz, vis);
    }
}

int main(){
    int V, E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    int **edges = (int**)malloc(E * sizeof(int*));
    for(int i = 0; i < E; i++){
        edges[i] = (int*)malloc(2 * sizeof(int));
    }

    int *sz = (int*)calloc(V, sizeof(int));

    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++){
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        sz[edges[i][0]]++;
    }

    int **g = (int**)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++){
        g[i] = (int*)malloc(sz[i] * sizeof(int));
        sz[i] = 0;
    }

    for(int i = 0; i < E; i++){
        int u = edges[i][0], v = edges[i][1];
        g[u][sz[u]++] = v;
    }

    int *vis = (int*)calloc(V, sizeof(int));

    // Step 1: fill stack
    for(int i = 0; i < V; i++){
        if(!vis[i])
            dfs1(i, g, sz, vis);
    }

    // Step 2: reverse graph
    int *szT = (int*)calloc(V, sizeof(int));

    for(int i = 0; i < E; i++){
        szT[edges[i][1]]++;
    }

    int **gt = (int**)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++){
        gt[i] = (int*)malloc(szT[i] * sizeof(int));
        szT[i] = 0;
    }

    for(int i = 0; i < E; i++){
        int u = edges[i][0], v = edges[i][1];
        gt[v][szT[v]++] = u;
    }

    // Step 3: DFS on reversed graph
    for(int i = 0; i < V; i++) vis[i] = 0;

    int scc = 0;

    while(!empty()){
        int u = pop();
        if(!vis[u]){
            scc++;
            dfs2(u, gt, szT, vis);
        }
    }

    printf("Number of SCCs: %d\n", scc);

    return 0;
}