//Problem Statement Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
struct Hash {
    int sum;
    int index;
};
int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;
    struct Hash hash[MAX];
    int hashSize = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0)
            max_len = i + 1;
        int found = 0;
        for (int j = 0; j < hashSize; j++) {
            if (hash[j].sum == sum) {
                int len = i - hash[j].index;
                if (len > max_len)
                    max_len = len;
                found = 1;
                break;
            }
        }
        if (!found) {
            hash[hashSize].sum = sum;
            hash[hashSize].index = i;
            hashSize++;
        }
    }
    return max_len;
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = maxLen(arr, n);
    printf("Length of longest subarray with sum 0 = %d\n", result);
    return 0;
}

/*Output
Enter number of elements: 8
Enter elements:
25 -2 2 -8 1 7 10 23
Length of longest subarray with sum 0 = 5
*/