//write a program to create a voting system
#include <stdio.h>
int main() {
    int age;
    int is_citizen;
    printf("Enter your age: ");
    scanf("%d", &age);

    // Validate if the age is a positive number
    if (age < 0) {
        printf("Invalid age! Age cannot be negative.\n");
    } else {
        // Prompt for citizenship status
        printf("Are you a citizen? (Enter 1 for Yes, 0 for No): ");
        scanf("%d", &is_citizen);

        // Check eligibility criteria
        if (age >= 18 && is_citizen == 1) {
            printf("\nCongratulations! You are eligible to vote.\n");
        } else if (age >= 18 && is_citizen != 1) {
            printf("\nSorry, you must be a citizen to vote in this region.\n");
        } else {
            int years_left = 18 - age;
            printf("\nYou are not eligible to vote yet.\n");
            printf("You must wait %d more year(s) to become eligible.\n", years_left);
        }
    }

    return 0;
}
