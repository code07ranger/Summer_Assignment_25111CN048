//Write a program to Find maximum occurring character.
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int freq[256] = {0};
    int i, maxFreq = 0, maxChar = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
    }

    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i;
        }
    }

    printf("Maximum occurring character is '%c' with frequency %d\n", maxChar, maxFreq);

    return 0;
}
