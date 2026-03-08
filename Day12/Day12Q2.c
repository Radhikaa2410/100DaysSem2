#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isToeplitzMatrix(int** Matrix , int MatrixSize , int* MatrixColSize){
    for(int i =1; i<MatrixSize; i++){
        for(int j=1; j<MatrixColSize[0]; j++){
            if(Matrix[i][j] != Matrix[i-1][j-1]){
        return false;
            }
        }
    }
    return true;
}
int main(){
    int m ,n ;
    printf("Enter umber of rows(m):");
    scanf("%d", &m);
    printf("Enter number of columns (n):");
    scanf("%d",&n);
    
    int** Matrix = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i<m; i++){
        Matrix[i]= (int*)malloc(n * sizeof(int));
    }
    int* MatrixColSize = (int*)malloc(sizeof(int));
    MatrixColSize[0] = n;

    printf("Enter elements of the matrix (%d x %d):\n",m,n);
    for(int i =0; i<m; i++){
        for(int j=0; j<n ;j++){
            scanf("%d",&Matrix[i][j]);
        }
    }
    printf("Matrix (%d x %d):\n" , m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d", Matrix[i][j]);
        }
        printf("\n");
    }

    if(isToeplitzMatrix(Matrix ,m , MatrixColSize)){
        printf("The matrix is Teoplitz.\n");
    } else {
        printf("The matrix is not Teoplitz.\n");
    }

    for(int i =0; i<m;i++){
        free(Matrix[i]);
    }
    free(Matrix);
    free(MatrixColSize);
    
    return 0;
}