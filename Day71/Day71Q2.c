#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mn(int a, int b){
    return a < b ? a : b;
}

int ab(int x){
    return x < 0 ? -x : x;
}

int cost(int** p, int n){
    int *d = (int*)malloc(n * sizeof(int));
    int *vis = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++)
        d[i] = INT_MAX;

    d[0] = 0;
    int res = 0;

    for(int i = 0; i < n; i++){
        int u = -1;

        for(int j = 0; j < n; j++){
            if(!vis[j] && (u == -1 || d[j] < d[u]))
                u = j;
        }

        vis[u] = 1;
        res += d[u];

        for(int v = 0; v < n; v++){
            if(!vis[v]){
                int dist = ab(p[u][0] - p[v][0]) +
                           ab(p[u][1] - p[v][1]);

                d[v] = mn(d[v], dist);
            }
        }
    }

    free(d);
    free(vis);
    return res;
}

int main(){
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);

    int** p = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        p[i] = (int*)malloc(2 * sizeof(int));
        printf("Enter x y for point %d: ", i+1);
        scanf("%d %d", &p[i][0], &p[i][1]);
    }

    printf("Minimum Cost: %d\n", cost(p, n));

    for(int i = 0; i < n; i++)
        free(p[i]);
    free(p);

    return 0;
}