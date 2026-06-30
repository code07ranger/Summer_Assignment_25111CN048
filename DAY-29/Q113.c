//Write a program to Create menu-driven calculator.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    // Infinite loop to keep the menu active until explicitly exited
    while (1) {
        // Displaying the Calculator Menu
        printf("\n=============================\n");
        printf("    MENU-DRIVEN CALCULATOR   \n");
        printf("=============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("=============================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Terminate immediately if the user selects choice 5
        if (choice == 5) {
            printf("\nExiting the calculator. Goodbye!\n");
            break; 
        }

        // Validate the operational choice before prompting for inputs
        if (choice < 1 || choice > 5) {
            printf("\nError: Invalid option! Please select between 1 and 5.\n");
            continue; // Skip the rest of the loop and prompt again
        }

        // Get numbers for calculation
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Process operations using switch-case
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                // Strategic runtime defense against division by zero
                if (num2 == 0) {
                    printf("\nError: Mathematical division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            default:
                printf("\nUnexpected system anomaly.\n");
                break;
        }
    }

    return 0;
}