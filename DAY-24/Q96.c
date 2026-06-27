//Write a program to Remove duplicate characters.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void removeDuplicates(char* str) {
    bool seen[256] = { false };
    
    int writeIndex = 0;
    int readIndex = 0;

    // Traverse the string
    while (str[readIndex] != '\0') {
        unsigned char ch = str[readIndex];

        // If the character hasn't been seen yet
        if (!seen[ch]) {
            seen[ch] = true;
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    str[writeIndex] = '\0';
}

int main() {
    char str[] = "programming language";
    printf("Original String: %s\n", str);
    removeDuplicates(str);
    printf("After Removing Duplicates: %s\n", str);
    return 0;
}
