/* Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true

Example 2:
Input: n = 16
Output: true

Example 3:
Input: n = 3
Output: false
*/

#include<stdio.h>
int main(){
    
    int n;
    printf("Enter an integer= ");
    scanf("%d", &n);

    if(n > 0 && (n & (n - 1)) == 0){
        printf("%d is a power of two.", n);
    }else{
        printf("%d is not a power of two.", n);
    }

    return 0;
}