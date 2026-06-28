//Write a program to Sort words by length.
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 100

int main() {
    char words[MAX_WORDS][100];
    int n, i, j;
    char temp[100];

    printf("Enter the number of words: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Sort words by length
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("Words sorted by length:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}