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
    if (n>=100) 
    {
        printf("Overflow\n");
        return 0;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the index where element is to be inserted: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) 
    {
        printf("Invalid index!\n");
        return 0;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &num);
    for (i = n; i > pos; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    n++;
    end = clock();   
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}
