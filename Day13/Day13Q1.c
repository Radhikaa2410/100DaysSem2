
//You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <stdio.h>
void spiralTraversal (int rows , int cols,int Matrix[rows][cols]){
    int top =0;
    int bottom = rows -1;
    int left = 0; 
    int right = cols-1;

    while(top <= bottom  && left <= right){
        for(int i=left ; i<= right;i++){
            printf("%d " , Matrix[top][i]);
        }
        top++;

        for(int i= top;i<=bottom ;i++){
            printf("%d ", Matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i= right ; i>= left;i--){
                printf("%d ",Matrix[bottom][i]);
            }
            bottom--;
        }

        if(left<= right){
            for(int i = bottom ;i>= top;i--){
                printf("%d ",Matrix[i][left]);
            }
            left++;
        }
    }
}

void printMatrix(int rows,int cols, int Matrix[rows][cols]){
printf("Matrix:\n");
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        printf("%d ",Matrix[i][j]);
    }
    printf("\n");
}
}

int main (){
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int Matrix[rows][cols];

    // Take matrix elements input
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &Matrix[i][j]);
        }
    }


    printMatrix(rows, cols, Matrix);

    printf("\nSpiral Traversal:\n");
    spiralTraversal(rows,cols,Matrix);
    return 0;

}
