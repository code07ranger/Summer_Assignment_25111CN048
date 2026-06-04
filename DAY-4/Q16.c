//Write a program to Print Armstrong numbers in a range.
#include <stdio.h>
int main() {
    for(int j=100;j<=999;j++){
    int  og, r, result = 0;
    og = j;  // Store the original number to compare later
    // Process each digit of the number
    for (int i=1;og!=0;i++){
        r=og%10;  // Extract the last digit
        result+=r*r*r;  // Add the cube of the digit
        og/=10;  // Remove the last digit
    }
    // Check if the result equals the original number
    if (result==j){
        printf("%d is an Armstrong number.\n",j);
    }
}
         return 0;
}