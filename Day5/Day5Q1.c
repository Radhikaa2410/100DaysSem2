//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>
int main()  {
    int n1, n2, i, j, k;
    int a[100], b[100], merged[200];
    printf("Enter number of entries in log 1: ");
    scanf("%d", &n1);
    printf("Enter %d arrival times (sorted):\n", n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    printf("Enter number of entries in log 2: ");
    scanf("%d", &n2);
    printf("Enter %d arrival times (sorted):\n", n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)  {
        if (a[i] <= b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];  }
    while (i < n1)
        merged[k++] = a[i++];
    while (j < n2)
        merged[k++] = b[j++];
    printf("Merged chronological log:\n");
    for (i = 0; i < k; i++)
        printf("%d ", merged[i]);
    return 0;
}

/*Output
Enter number of entries in log 1: 5
Enter 5 arrival times (sorted):
10 20 30 40 50
Enter number of entries in log 2: 4
Enter 4 arrival times (sorted):
15 25 28 32
Merged chronological log:
10 15 20 25 28 30 32 40 50 
*/