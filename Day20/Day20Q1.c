
#include<stdio.h>
int main(){
int n , count = 0;
printf("Enter number of elements:");
scanf("%d" , &n);

int A[n];
printf("Enter elements :\n");
for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
}

for(int i=0;i<n;i++){
    int sum = 0;
    for(int j=0;j<n;j++){
        sum += A[j];
        if(sum == 0){
            count++;
        }
    }
}
printf("Number of subarrays with sum = 0 is %d" , count);
return 0;
}
