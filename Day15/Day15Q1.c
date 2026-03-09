
//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include<stdio.h>

void printMatrix(int n,int matrix[n][n]){
    printf("The matrix is:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the size of the square matrix:");
    scanf("%d",&n);

    int matrix[n][n];
    int sum = 0;

    printf("Enter the elements of matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            if( i==j) {
                 sum += matrix[i][j];
            }
        }
    }
    printMatrix(n, matrix);
    printf("Sum of primary diagonal elements = %d\n" ,sum);
    return 0;
}
