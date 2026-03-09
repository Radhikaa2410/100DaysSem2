//Given an array of integers, rotate the array to the right by k positions
#include<stdio.h>
void reverse(int A[] , int start,int end){
    while(start<end){
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}

void rotate_right(int A[] , int n,int k){
    k = k %n;

    reverse(A , 0 ,n-1);
    reverse(A,0,k-1);
    reverse(A,k,n-1);
}

int main(){
    int n,k;
    printf("Enter size of array:");
    scanf("%d",&n);

    int A[n];

    printf("Enter %d elements :\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Enter value of k:");
    scanf("%d",&k);

    rotate_right(A,n,k);

    printf("Array after right rotation:\n");
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }
    return 0;
}