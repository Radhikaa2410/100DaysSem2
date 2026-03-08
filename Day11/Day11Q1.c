//Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.
 #include<stdio.h>

 void addMatrices(int rows, int cols, int M1[rows][cols], int M2[rows][cols], int sum[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main (){
    int rows,cols;

    printf("Enter number of rows:");
    scanf("%d",&rows);
    printf("Enter number of columns:");
    scanf("%d",&cols);

    int M1[rows][cols] , M2[rows][cols],sum[rows][cols];

    printf("Enter elements of first matrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Element [%d][%d]:",i+1,j+1 ) ;
            scanf("%d",&M1[i][j]);

        }

    }
    printf("Enter elements of second matrix.\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Element [%d][%d]: " ,i+1,j+1);
            scanf("%d",&M2[i][j]);
        }
    }

    addMatrices(rows, cols,M1,M2,sum);


    printf("\nFirst Matrix:\n");
    printMatrix(rows, cols, M1);

    printf("\nSecond Matrix:\n");
    printMatrix(rows, cols, M2);

    printf("\nSum of the two matrices:\n");
    printMatrix(rows, cols, sum);
}