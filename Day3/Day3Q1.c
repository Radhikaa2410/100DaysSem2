#include <stdio.h>
int main() 
{
    int a[100], n, i, x, c = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++) 
    {
        c++;             
        if (a[i] == x) 
        {
            printf("Found at index %d\n", i);
            break;
        }
    }
    if (i==n) 
    {
        printf("Not found\n");
    }
    printf("Comparisons = %d\n", c);
    return 0;
}
