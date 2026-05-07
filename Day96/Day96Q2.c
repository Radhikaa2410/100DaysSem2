#include <stdio.h>
#include <stdlib.h>

// Function to count reverse pairs during merge step
int countWhileMerge(int arr[], int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {

        // Count elements satisfying:
        // arr[i] > 2 * arr[j]
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }

        count += (j - (mid + 1));
    }

    return count;
}

// Merge two sorted halves
void merge(int arr[], int left, int mid, int right) {

    int n = right - left + 1;

    int *temp = (int *)malloc(n * sizeof(int));

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = 0; i < n; i++) {
        arr[left + i] = temp[i];
    }

    free(temp);
}

// Merge Sort + Reverse Pair Count
int mergeSort(int arr[], int left, int right) {

    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int count = 0;

    // Left half
    count += mergeSort(arr, left, mid);

    // Right half
    count += mergeSort(arr, mid + 1, right);

    // Count reverse pairs
    count += countWhileMerge(arr, left, mid, right);

    // Merge sorted halves
    merge(arr, left, mid, right);

    return count;
}

// Main function
int main() {

    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = mergeSort(arr, 0, n - 1);

    printf("Number of reverse pairs = %d\n", result);

    free(arr);

    return 0;
}