#include <stdio.h>
#include <limits.h>

#define MAX 101

int city(int n, int **e, int m, int th){
    int d[MAX][MAX];

    // init
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INT_MAX;
        }
    }

    // edges
    for(int i = 0; i < m; i++){
        int u = e[i][0], v = e[i][1], w = e[i][2];
        d[u][v] = w;
        d[v][u] = w;
    }

    // Floyd Warshall
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] != INT_MAX && d[k][j] != INT_MAX &&
                   d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int ans = -1, mn = INT_MAX;

    for(int i = 0; i < n; i++){
        int cnt = 0;

        for(int j = 0; j < n; j++){
            if(i != j && d[i][j] <= th)
                cnt++;
        }

        if(cnt <= mn){
            mn = cnt;
            ans = i; // larger index preferred automatically
        }
    }

    return ans;
}

int main(){
    int n, m, th;

    printf("Enter number of cities and edges: ");
    scanf("%d %d", &n, &m);

    int e[m][3];

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
    }

    printf("Enter threshold: ");
    scanf("%d", &th);

    int *ptrs[m];
    for(int i = 0; i < m; i++)
        ptrs[i] = e[i];

    printf("Answer City: %d\n", city(n, ptrs, m, th));

    return 0;
}