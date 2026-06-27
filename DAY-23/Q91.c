//Write a program to Check anagram strings.
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256

int areAnagrams(char *str1, char *str2) {
    int freq[MAX_CHAR] = {0};
    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        freq[(unsigned char)str1[i]]++;
    }
    for (i = 0; str2[i] != '\0'; i++) {
        freq[(unsigned char)str2[i]]--;
    }
    for (i = 0; i < MAX_CHAR; i++) {
        if (freq[i] != 0) {
            return 0; // Not anagrams
        }
    }

    return 1; // Anagrams
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    if (fgets(str1, sizeof(str1), stdin)) {
        str1[strcspn(str1, "\n")] = '\0';
    }

    printf("Enter second string: ");
    if (fgets(str2, sizeof(str2), stdin)) {
        str2[strcspn(str2, "\n")] = '\0';
    }

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
