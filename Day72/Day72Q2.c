#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
int **dp;

int mn(int a, int b){
    return a < b ? a : b;
}

int f(int m, int p, int **c){
    if(m == (1 << n) - 1)
        return c[p][0];

    if(dp[m][p] != -1)
        return dp[m][p];

    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        if((m & (1 << i)) == 0){
            int cur = c[p][i] + f(m | (1 << i), i, c);
            ans = mn(ans, cur);
        }
    }

    return dp[m][p] = ans;
}

int tsp(int **c){
    dp = (int**)malloc((1 << n) * sizeof(int*));
    
    for(int i = 0; i < (1 << n); i++){
        dp[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    return f(1, 0, c);
}

int main(){
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int **c = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        c[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &c[i][j]);
        }
    }

    int res = tsp(c);
    printf("Minimum Cost: %d\n", res);

    // Free memory
    for(int i = 0; i < (1 << n); i++)
        free(dp[i]);
    free(dp);

    for(int i = 0; i < n; i++)
        free(c[i]);
    free(c);

    return 0;
}