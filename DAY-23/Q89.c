//Write a program to Find first non-repeating character.
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
char findFirstNonRepeating(char *str) {
    int freq[MAX_CHAR] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }

    return '\0'; // Return null character if no unique character exists
}

int main() {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
    }

    char result = findFirstNonRepeating(str);

    if (result != '\0') {
        printf("The first non-repeating character is: '%c'\n", result);
    } else {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}
