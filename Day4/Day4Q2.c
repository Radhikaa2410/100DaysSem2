#include <stdio.h>

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // write pointer
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() { 
    int n, val;
   
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int nums[n];

     printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter the value to remove: ");
    scanf("%d", &val);
    
    int k = removeElement(nums, n, val);
    
    printf("Number of elements not equal to %d: %d\n", val, k);
    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}