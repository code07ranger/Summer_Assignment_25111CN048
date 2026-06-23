//Write a program to Intersection of arrays.
#include <stdio.h>

// Function to check if an element already exists in the result array
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Found a duplicate
        }
    }
    return 0; // Not a duplicate
}

// Function to find and print the intersection of two arrays
void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int intersection[100]; // Array to store common elements
    int k = 0;             // Counter for intersection array

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            // If elements match, check if it's already added to avoid repeats
            if (arr1[i] == arr2[j]) {
                if (!isDuplicate(intersection, k, arr1[i])) {
                    intersection[k] = arr1[i];
                    k++;
                }
                break; // Move to the next element in arr1
            }
        }
    }

    // Print the result
    if (k == 0) {
        printf("No common elements found.\n");
    } else {
        printf("Intersection of the two arrays: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
}

int main() {
    int size1, size2;

    // Input size and elements for the first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter elements of the first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size and elements for the second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter elements of the second array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Call the intersection function
    findIntersection(arr1, size1, arr2, size2);

    return 0;
}