//Write a program to Count set bits in a number.
#include <stdio.h>
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1; // Increment count if the last bit is set
        n = n >> 1; // Right shift the bits by 1
    }
    return count;
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int setBitsCount = countSetBits(number);
    printf("Number of set bits in %d is: %d\n", number, setBitsCount);
    return 0;
}
