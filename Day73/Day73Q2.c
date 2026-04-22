#include <stdio.h>
#include <stdlib.h>

int fd(int p[], int x){
    if(p[x] != x)
        p[x] = fd(p, p[x]);
    return p[x];
}

void un(int p[], int x, int y){
    int px = fd(p, x);
    int py = fd(p, y);
    if(px != py)
        p[px] = py;
}

int main(){
    int n;
    printf("Enter number of edges: ");
    scanf("%d", &n);

    int **e = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        e[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < n; i++){
        scanf("%d %d", &e[i][0], &e[i][1]);
    }

    int *p = (int*)malloc((n + 1) * sizeof(int));

    for(int i = 1; i <= n; i++)
        p[i] = i;

    int a = -1, b = -1;

    for(int i = 0; i < n; i++){
        int u = e[i][0];
        int v = e[i][1];

        if(fd(p, u) == fd(p, v)){
            a = u;
            b = v;   // store last redundant edge
        } else {
            un(p, u, v);
        }
    }

    printf("Redundant Edge: [%d, %d]\n", a, b);

    // free memory
    for(int i = 0; i < n; i++)
        free(e[i]);
    free(e);
    free(p);

    return 0;
}