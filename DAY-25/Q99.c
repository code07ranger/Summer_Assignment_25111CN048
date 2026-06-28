//Write a program to Sort names alphabetically.
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char names[100][50], temp[50];

    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d names:\n", n);
    for(i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = 0; // Remove newline character
    }

    // Sorting names alphabetically using bubble sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}