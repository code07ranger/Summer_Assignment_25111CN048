//Write a program to Compress a string.
#include <stdio.h>
#include <string.h>

void compressString(char str[]) {
    int len = strlen(str);
    if (len == 0) return;

    char compressed[2 * len + 1];
    int index = 0;
    char current = str[0];
    int count = 1;
for (int i = 1; i < len; i++) {
        if (str[i] == current) {
            count++;
        } else {
            compressed[index++] = current;
            compressed[index++] = count + '0';
            current = str[i];
            count = 1;
        }
    }
    compressed[index++] = current;
    compressed[index++] = count + '0';
    compressed[index] = '\0';

    strcpy(str, compressed);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    compressString(str);
    printf("Compressed string: %s\n", str);
    return 0;
}