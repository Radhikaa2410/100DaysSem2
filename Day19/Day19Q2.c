
#include <stdio.h>
#include <limits.h>

// Kadane for maximum subarray
int kadaneMax(int arr[], int n) {
    int maxSum = arr[0], curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = (curr + arr[i] > arr[i]) ? curr + arr[i] : arr[i];
        if (curr > maxSum)
            maxSum = curr;
    }
    return maxSum;
}

// Kadane for minimum subarray
int kadaneMin(int arr[], int n) {
    int minSum = arr[0], curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = (curr + arr[i] < arr[i]) ? curr + arr[i] : arr[i];
        if (curr < minSum)
            minSum = curr;
    }
    return minSum;
}

// Function to find maximum circular subarray sum
int maxSubarraySumCircular(int arr[], int n) {
    int normalMax = kadaneMax(arr, n);

    // If all numbers are negative
    if (normalMax < 0)
        return normalMax;

    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    int minSum = kadaneMin(arr, n);

    int circularMax = total - minSum;

    return (normalMax > circularMax) ? normalMax : circularMax;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubarraySumCircular(arr, n);

    printf("Maximum circular subarray sum = %d\n", result);

    return 0;
}
