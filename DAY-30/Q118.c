//Write a program to Create mini library system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define STR_LEN 50

// Define a Book Structure
typedef struct {
    int id;
    char title[STR_LEN];
    char author[STR_LEN];
    int copies;
} Book;

// Global array and counter to track inventory
Book library[MAX_BOOKS];
int bookCount = 0;

// Function Prototypes
void addBook();
void viewBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    MINI LIBRARY SYSTEM");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. View All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error]: Invalid option format!\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\n[Error]: Choice out of range. Try again.\n");
        }
    }
    return 0;
}

// 1. Add New Book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\n[Error]: Library storage is full!\n");
        return;
    }

    Book newBook;
    printf("\nEnter unique Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("[Error]: ID must be a number.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Check for ID duplication
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("[Error]: Book ID %d already exists!\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, STR_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Strip newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, STR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter Number of Copies: ");
    if (scanf("%d", &newBook.copies) != 1 || newBook.copies < 0) {
        printf("[Error]: Invalid copy count.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    library[bookCount] = newBook;
    bookCount++;
    printf("\n[Success]: Book successfully added to catalog!\n");
}

// 2. View All Books
void viewBooks() {
    if (bookCount == 0) {
        printf("\n[Info]: No books in the library catalog.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-10s\n", "ID", "Title", "Author", "Copies Available");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-25s %-10d\n", library[i].id, library[i].title, library[i].author, library[i].copies);
    }
}

// 3. Search for a Book
void searchBook() {
    if (bookCount == 0) {
        printf("\n[Info]: Library catalog is empty.\n");
        return;
    }

    char query[STR_LEN];
    int found = 0;

    printf("\nEnter Title or Author keyword to search: ");
    fgets(query, STR_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';

    printf("\nSearch Results:\n");
    printf("%-10s %-30s %-25s %-10s\n", "ID", "Title", "Author", "Copies");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        // Partial case-sensitive text matching
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("%-10d %-30s %-25s %-10d\n", library[i].id, library[i].title, library[i].author, library[i].copies);
            found = 1;
        }
    }

    if (!found) {
        printf("\n[Info]: No books match your search query.\n");
    }
}

// 4. Issue a Book
void issueBook() {
    int targetId;
    printf("\nEnter Book ID to issue: ");
    if (scanf("%d", &targetId) != 1) {
        printf("[Error]: Invalid ID format.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            if (library[i].copies > 0) {
                library[i].copies--;
                printf("\n[Success]: Book issued successfully! Remaining copies: %d\n", library[i].copies);
            } else {
                printf("\n[Error]: Book out of stock!\n");
            }
            return;
        }
    }
    printf("\n[Error]: Book ID %d not found.\n", targetId);
}

// 5. Return a Book
void returnBook() {
    int targetId;
    printf("\nEnter Book ID to return: ");
    if (scanf("%d", &targetId) != 1) {
        printf("[Error]: Invalid ID format.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            library[i].copies++;
            printf("\n[Success]: Book returned successfully! Total copies: %d\n", library[i].copies);
            return;
        }
    }
    printf("\n[Error]: Book ID %d does not belong to this library system.\n", targetId);
}

// Input utility buffer clearing tool (prevents string input skipping errors)
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}