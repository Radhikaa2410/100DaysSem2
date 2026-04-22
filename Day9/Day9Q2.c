/* Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <stdio.h>
void reverseString(char s[], int n){
    int left = 0, right = n - 1;
    char temp;

    while(left < right){
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main(){

    char s[100];
    int n = 0;

    scanf("%s", s);
    while(s[n] != '\0'){
        n++;
    }

    reverseString(s, n);

    printf("%s", s);

    return 0;
}