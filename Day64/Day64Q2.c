#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} P;

// Function
int orangesRotting(int** g, int r, int* c) {
    int cols = c[0];

    P q[r * cols];
    int f = 0, b = 0;

    int fresh = 0;

    // Initialize queue
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == 2)
                q[b++] = (P){i, j};
            else if (g[i][j] == 1)
                fresh++;
        }
    }

    if (fresh == 0) return 0;

    int min = 0;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (f < b) {
        int size = b - f;
        int inf = 0;

        for (int i = 0; i < size; i++) {
            P p = q[f++];

            for (int d = 0; d < 4; d++) {
                int nx = p.x + dir[d][0];
                int ny = p.y + dir[d][1];

                if (nx >= 0 && ny >= 0 && nx < r && ny < cols && g[nx][ny] == 1) {
                    g[nx][ny] = 2;
                    q[b++] = (P){nx, ny};
                    fresh--;
                    inf = 1;
                }
            }
        }

        if (inf) min++;
    }

    return (fresh == 0) ? min : -1;
}

// Main
int main() {
    int r, col;

    printf("Enter rows: ");
    scanf("%d", &r);

    printf("Enter cols: ");
    scanf("%d", &col);

    int** g = (int**)malloc(r * sizeof(int*));
    int* c = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        g[i] = (int*)malloc(col * sizeof(int));
        c[i] = col;
    }

    printf("Enter grid:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    int res = orangesRotting(g, r, c);

    printf("Output: %d\n", res);

    // Free memory
    for (int i = 0; i < r; i++) {
        free(g[i]);
    }
    free(g);
    free(c);

    return 0;
}