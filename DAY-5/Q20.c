//Write a program to Find largest prime factor.
#include <stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int largest_prime_factor = -1;
    for (int i=2;i<=n;i++) {
        while (n % i == 0) {
            largest_prime_factor = i;
            n /= i;
        }
    }
    if (largest_prime_factor != -1) {
        printf("The largest prime factor is: %d\n", largest_prime_factor);
    } else {
        printf("No prime factors found.\n");
    }

    return 0;
}