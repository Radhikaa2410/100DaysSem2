
#include<stdio.h>
#include<stdlib.h>

void rotate(int** matrix , int matrixSize , int* matrixColSize){
    int n = matrixSize;
    
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n/2 ; j++){
            int temp  = matrix[i][j];
            matrix[i][j] = matrix[i][n-j-1];
            matrix[i][n-j-1] = temp;
        }
    }
}

void printMatrix(int** matrix, int n){
    for(int i=0;i<n;i++){
      for(int j=0; j<n; j++){
      printf("%d",matrix[i][j]);
    }
    printf("\n");
}
}
int main(){
    int n;
    printf("Enter the size of square matrix:");
    scanf("%d",&n);

    int* matrixColSize  = (int*)malloc(n * sizeof(int));
    *matrixColSize = n;

    int** matrix = (int**)malloc(n *sizeof(int*));
    for(int i=0; i<n; i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the martix: \n");
    for(int i=0 ; i<n; i++){
        for(int j = 0;j<n;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix , n);

    rotate(matrix , n , matrixColSize);

    printf("\nRotated matrix:\n");
    printMatrix(matrix , n);

    for(int i = 0;i<n;i++){
    free(matrix[i]);
}
free(matrix);
free(matrixColSize);

return 0;

}
