//Write a program to Create menu-driven array operations system.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void display(int arr[], int size);
int insertElement(int arr[], int size, int element, int position);
int deleteElement(int arr[], int size, int position);
int searchElement(int arr[], int size, int element);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, index, i;

    // Initializing the array
    printf("Enter the initial number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size < 0) {
        printf("Invalid size! Exiting program.\n");
        return 1;
    }

    if (size > 0) {
        printf("Enter %d elements:\n", size);
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    // Infinite loop for the menu-driven system
    while (1) {
        printf("\n========== ARRAY OPERATIONS MENU ==========\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element (Linear Search)\n");
        printf("5. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, size);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &position);
                
                // Update size if insertion is successful
                size = insertElement(arr, size, element, position);
                break;

            case 3:
                if (size == 0) {
                    printf("Underflow! Array is empty. Nothing to delete.\n");
                    break;
                }
                printf("Enter the position to delete from (0 to %d): ", size - 1);
                scanf("%d", &position);
                
                // Update size if deletion is successful
                size = deleteElement(arr, size, position);
                break;

            case 4:
                if (size == 0) {
                    printf("Array is empty. Nothing to search.\n");
                    break;
                }
                printf("Enter the element to search for: ");
                scanf("%d", &element);
                
                index = searchElement(arr, size, element);
                if (index != -1) {
                    printf("Element %d found at index %d (Position %d).\n", element, index, index + 1);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;

            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

// 1. Function to display array elements
void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Function to insert an element at a specific index
int insertElement(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Overflow! Cannot insert element. Array is full.\n");
        return size;
    }
    if (position < 0 || position > size) {
        printf("Invalid position! Position must be between 0 and %d.\n", size);
        return size;
    }

    // Shift elements to the right to make space
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    printf("Element %d successfully inserted at position %d.\n", element, position);
    return size + 1; // Return updated size
}

// 3. Function to delete an element from a specific index
int deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position! Position must be between 0 and %d.\n", size - 1);
        return size;
    }

    int deletedValue = arr[position];
    
    // Shift elements to the left to cover the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element %d successfully deleted from position %d.\n", deletedValue, position);
    return size - 1; // Return updated size
}

// 4. Function to search for an element (Linear Search)
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return index of found element
        }
    }
    return -1; // Return -1 if not found
}