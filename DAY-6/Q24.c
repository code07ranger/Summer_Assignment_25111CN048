//Write a program to Find x^n without pow().
#include <stdio.h>
double power(double x, int n) {
    double result = 1.0;
    int exponent = n > 0 ? n : -n; // Handle negative exponent
    for (int i = 0; i < exponent; i++) {
        result *= x;
    }
    return n >= 0 ? result : 1.0 / result; // If n
} is negative, return the reciprocal
int main() {
    double x;
    int n;
    printf("Enter a base (x): ");
    scanf("%lf", &x);
    printf("Enter an exponent (n): ");
    scanf("%d", &n);
    double result = power(x, n);
    printf("%.2lf raised to the power of %d is: %.2lf\n", x, n, result);
    return 0;
}
