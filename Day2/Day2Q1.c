#include <stdio.h>
#include <time.h>
int main() 
{
    int arr[100];
    int n, i, pos, num;
    clock_t start, end;
    double cpu_time_used;
    start = clock();   
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Underflow.\n");
        return 0;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i<n; i++) 
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the index where element is to be deleted: ");
    scanf("%d", &pos);
    if (pos<0 || pos>n) 
    {
        printf("Invalid index\n");
        return 0;
    }
    for (i = pos; i<n; i++) 
    {
        arr[i] = arr[i + 1];
    }
    n--;
    end = clock();  
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array after deletion:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}
