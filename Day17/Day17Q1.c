
// Write a program to find the maximum and minimum values present in a given array of integers.
#include<stdio.h>
int main(){
    int n,i;

    printf("Enter number of elements:");
    scanf("%d" ,&n);
    int A[n];

    printf("Enter elements:\n");
    for(i = 0;i<n;i++){
        scanf("%d",&A[i]); 
    }
    int max = A[0] ;
    int min = A[0];

    for( i =1;i<n;i++){
        if(A[i] < min){
            min = A[i];
        }
        if(A[i] > max){
            max = A[i];
        }
    }
     printf("Minimum value = %d\n", min);
    printf("Maximum value = %d\n", max);
    return 0;
}
