#include <stdio.h>
int main() 
{
    int a[100], n, i, t;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n / 2; i++) 
    {
        t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
    printf("Reversed array:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
    return 0;
}
