//Write a program to Find common elements.
#include <stdio.h>

int main() {
    // Initialize two sample arrays
    int array1[] = {1, 2, 4, 5, 5, 8, 9};
    int array2[] = {2, 3, 5, 7, 8, 10};
    
    // Calculate the size of both arrays
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    printf("Array 1: ");
    for(int i = 0; i < size1; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    
    printf("Array 2: ");
    for(int i = 0; i < size2; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n\n");
    
    printf("Common elements: ");
    
    // Nested loops to compare elements
    for (int i = 0; i < size1; i++) {
        // Check if array1[i] was already processed to avoid duplicate output
        int isDuplicate = 0;
        for (int k = 0; k < i; k++) {
            if (array1[i] == array1[k]) {
                isDuplicate = 1;
                break;
            }
        }
        
        // If it is a duplicate in array1, skip to the next element
        if (isDuplicate) {
            continue;
        }
        
        // Compare the current element of array1 with elements in array2
        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
                printf("%d ", array1[i]);
                break; // Break the inner loop once a match is found
            }
        }
    }
    
    printf("\n");
    return 0;
}