//Write a program to Find longest word.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char longestWord[100] = "";
    char *token = strtok(str, " ");
    while (token != NULL) {
        if (strlen(token) > strlen(longestWord)) {
            strcpy(longestWord, token);
        }
        token = strtok(NULL, " ");
    }
    printf("Longest word: %s\n", longestWord);
    return 0;
}