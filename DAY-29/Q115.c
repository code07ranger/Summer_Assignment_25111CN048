//Write a program to Create menu-driven array operations system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to clear the input buffer safely
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to safely read a string including spaces
void readString(char *str, int size) {
    fgets(str, size, stdin);
    // Remove the trailing newline character added by fgets
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
        // Displaying the system menu
        printf("\n====================================");
        printf("\n   STRING OPERATIONS SYSTEM MENU   ");
        printf("\n====================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid numeric selection.\n");
            clearBuffer();
            continue;
        }
        
        clearBuffer(); // Clear newline character after reading choice

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                readString(str1, sizeof(str1));
                printf("Length of the string: %lu\n", (unsigned long)strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string: ");
                readString(str1, sizeof(str1));
                strcpy(str2, str1);
                printf("Successfully copied!\n");
                printf("Destination String: %s\n", str2);
                break;

            case 3:
                printf("\nEnter the first string: ");
                readString(str1, sizeof(str1));
                printf("Enter the second string to append: ");
                readString(str2, sizeof(str2));
                
                // Prevent buffer overflow before combining
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated String: %s\n", str1);
                } else {
                    printf("\nError: Combined length exceeds memory buffer limit.\n");
                }
                break;

            case 4:
                printf("\nEnter the first string: ");
                readString(str1, sizeof(str1));
                printf("Enter the second string: ");
                readString(str2, sizeof(str2));
                
                int cmpResult = strcmp(str1, str2);
                if (cmpResult == 0) {
                    printf("Both strings are identical.\n");
                } else if (cmpResult > 0) {
                    printf("The first string is greater than the second string.\n");
                } else {
                    printf("The second string is greater than the first string.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                readString(str1, sizeof(str1));
                
                int len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[len - i - 1];
                    str1[len - i - 1] = temp;
                }
                printf("Reversed String: %s\n", str1);
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid option chosen. Please select between 1 and 6.\n");
        }
    }
    return 0;
}