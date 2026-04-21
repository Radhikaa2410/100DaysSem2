#include <stdio.h>
#include <stdlib.h>

// DFS
void dfs(int** img, int n, int* m, int r, int c, int old, int newC) {
    if (r < 0 || c < 0 || r >= n || c >= m[r])
        return;

    if (img[r][c] != old)
        return;

    img[r][c] = newC;

    dfs(img, n, m, r + 1, c, old, newC);
    dfs(img, n, m, r - 1, c, old, newC);
    dfs(img, n, m, r, c + 1, old, newC);
    dfs(img, n, m, r, c - 1, old, newC);
}

// Flood Fill
int** floodFill(int** img, int n, int* m, int sr, int sc, int col, int* rs, int** rcs) {
    int old = img[sr][sc];

    if (old == col) {
        *rs = n;
        *rcs = m;
        return img;
    }

    dfs(img, n, m, sr, sc, old, col);

    *rs = n;
    *rcs = m;

    return img;
}

// Main
int main() {
    int n, c;

    printf("Enter rows: ");
    scanf("%d", &n);

    printf("Enter cols: ");
    scanf("%d", &c);

    int** img = (int**)malloc(n * sizeof(int*));
    int* m = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        img[i] = (int*)malloc(c * sizeof(int));
        m[i] = c;
    }

    printf("Enter image:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &img[i][j]);
        }
    }

    int sr, sc, col;
    printf("Enter sr sc and new color: ");
    scanf("%d %d %d", &sr, &sc, &col);

    int rs;
    int* rcs;

    int** res = floodFill(img, n, m, sr, sc, col, &rs, &rcs);

    printf("Result:\n");
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < rcs[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(img[i]);
    }
    free(img);
    free(m);

    return 0;
}