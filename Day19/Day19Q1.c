
#include<stdio.h>
#include<stdlib.h>

void closesttoZero(int A[],int n){
    if(n<2){
        printf("At least two elements required.\n");
        return ;
    }

    int minSum = A[0] + A[1];
    int a = A[0] , b = A[1];

    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int  sum = A[i] + A[j];
        if(abs(sum)<abs(minSum)){
            minSum = sum;
            a = A[i];
            b= A[j];
        }
    }
}
printf("Pair closest to zero : %d and %d\n" ,a, b);
}

int main(){
   int n;

   printf("Enter number of elements:");
   scanf("%d",&n);

   int A[n];

   printf("Enter %d elements :\n" , n );
   for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
   }
   closesttoZero(A ,n);
   return 0;
}
