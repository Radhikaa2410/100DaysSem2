
#include<stdio.h>
int main(){
int n;

printf("Enter number of elemtents :");
scanf("%d",&n);

int arr[n];
int visited[n];

for(int i=0;i<n;i++){
    visited[i] = 0;
}

printf("Enter elements:");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

printf("\n Frequency of elements :\n");

for(int i=0;i<n;i++){
    if(visited[i] == 1)
        continue;

        int count = 1;

        for( int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
                visited[j] = 1;
            }
        }
        printf("%d occurs %d times\n",arr[i],count);
    }
return 0;
}
