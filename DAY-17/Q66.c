//Write a program to Union of arrays.
#include <stdio.h>
#include <stdbool.h>

// Function to check if an element is already present in an array
bool isPresent(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true; // Element found
        }
    }
    return false; // Element not found
}

// Function to find the union of two arrays
int findUnion(int arr1[], int size1, int arr2[], int size2, int unionArr[]) {
    int unionSize = 0;

    // 1. Add all unique elements from the first array
    for (int i = 0; i < size1; i++) {
        if (!isPresent(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    // 2. Add elements from the second array if they are not already in the union
    for (int i = 0; i < size2; i++) {
        if (!isPresent(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    return unionSize; // Return the total number of elements in the union
}

int main() {
    // Define two example arrays with duplicate values
    int arr1[] = {1, 2, 3, 2, 1};
    int arr2[] = {3, 2, 4, 5, 3};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // The maximum possible size of the union is the sum of both sizes
    int unionArr[size1 + size2];

    // Find the union
    int unionSize = findUnion(arr1, size1, arr2, size2, unionArr);

    // Print the result
    printf("Union of the two arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}