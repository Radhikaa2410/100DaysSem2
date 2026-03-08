#include<stdio.h>
#define MAX 10

void printMatrix(int matrix[MAX][MAX] , int n){
    printf("Matrix (%d x %d):\n" , n,n);
    for(int i=0;i<n ;i++){
        for(int j = 0;j<n;j++){
            printf("%d" , matrix[i][j]);
        }
        printf("\n");
    }

}

int isSymmetric(int matrix[MAX][MAX] , int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] != matrix[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int main (){
    int n;
    int matrix[MAX][MAX] ;

    printf("Enter size of the square matrix :");
    scanf("%d",&n);

    printf("Enter elements of the matrix (%d x %d):\n" , n ,n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
    
        }
    }

    printMatrix(matrix , n );
    
    if (isSymmetric(matrix , n)){
        printf("The matrix is symmetric.\n");  
    } else {
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}