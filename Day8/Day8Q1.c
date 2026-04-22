//Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>
int power(int a, int b) {
    if (b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}
int main() {
    int a, b;
    printf("Enter Base (a): ");
    scanf("%d", &a);
    printf("Enter Exponent (b): ");
    scanf("%d", &b);
    printf("%d^%d = %d\n", a, b, power(a, b));
    return 0;
}
/*Output
Enter Base (a): 5
Enter Exponent (b): 4
5^4 = 625
*/