#include <stdio.h>

// Function to merge two sorted arrays
void mergeLogs(int a[], int n1, int b[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge both arrays while comparing elements
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            merged[k] = a[i];
            i++;
        } else {
            merged[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of array a
    while (i < n1) {
        merged[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of array b
    while (j < n2) {
        merged[k] = b[j];
        j++;
        k++;
    }
}

int main() {
    int n1, n2;
    int a[100], b[100], merged[200];
    int i;

    // Input for first log
    printf("Enter number of entries in log 1: ");
    scanf("%d", &n1);

    printf("Enter %d arrival times (sorted):\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    // Input for second log
    printf("Enter number of entries in log 2: ");
    scanf("%d", &n2);

    printf("Enter %d arrival times (sorted):\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Call merge function
    mergeLogs(a, n1, b, n2, merged);

    // Print merged log
    printf("Merged chronological log:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}