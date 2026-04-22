/* Problem: Write a non - recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8
*/

#include <stdio.h>

int fib(int n){
    int a = 0, b = 1, c, i;

    if(n == 0){
        return 0;
    }if(n == 1){
        return 1;
    }
    
    for(i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    int n;
    printf("Enter the value of n = ");
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}