//Write a program to Convert lowercase to uppercase.
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    
    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin); // Safe alternative to gets()
    
    // Loop through each character until the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
    
    printf("Uppercase string: %s", str);
    return 0;
}