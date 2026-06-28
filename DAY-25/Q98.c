//Write a program to Find common characters in strings.
#include <stdio.h>
#include <string.h>
int main() {
    char str1[100], str2[100];
    int i, j, found;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    printf("Common characters: ");
    for (i = 0; str1[i] != '\0'; i++) {
        found = 0;
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                found = 1;
                break;
            }
        }
        if (found==1) {
            printf("%c ", str1[i]);
        }
    }
    return 0;
}