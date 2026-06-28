//Write a program to Merge two sorted arrays.
#include <stdio.h>
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0; // Index for arr1
    int j = 0; // Index for arr2
    int k = 0; // Index for merged array
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int totalSize = size1 + size2;
    int merged[totalSize];

    // Function call
    mergeSortedArrays(arr1, size1, arr2, size2, merged);
    printf("Merged Sorted Array: ");
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    return 0;
}
