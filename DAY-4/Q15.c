//Write a program to Check Armstrong number.
#include <stdio.h>
int main() {
    int n, og, r, result = 0;
    // Input number from user
    printf("Enter a three-digit number: ");
    scanf("%d", &n);
    og = n;  // Store the original number to compare later
    // Process each digit of the number
    for (int i=1;og!=0;i++){
        r=og%10;  // Extract the last digit
        result+=r*r*r;  // Add the cube of the digit
        og/=10;  // Remove the last digit
    }
    // Check if the result equals the original number
    if (result==n){
        printf("%d is an Armstrong number.\n",n);
    }
    else{
        printf("%d is not an Armstrong number.\n",n);
    }
         return 0;
}