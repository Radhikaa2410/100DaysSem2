
#include<stdio.h>
void printMatrix(int n, int matrix[n][n]) {
    int i, j;
    printf("The matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter the size of square matrix:");
    scanf("%d", &n);
    int matrix[n][n];
    int i ,j, isIdentity  =1;
    printf("Enter the elements of the matrix :\n");
    for(i=0; i<n; i++){
       for(j = 0;j  < n;j++){
            scanf("%d", &matrix[i][j]);
       }
    }

     printMatrix(n, matrix);
     
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j && matrix[i][j] != 1){
                isIdentity = 0;
                break;
            }
            else if (i != j && matrix[i][j] != 0){
                isIdentity = 0;
                break;
            }
        }
        if ( !isIdentity ) break;
    }

    if(isIdentity){
        printf("The matrix is an identity Matrix\n");
      }  else {
        printf("The matrix is not an identity matrix.\n");
      }
        return 0;
    }
