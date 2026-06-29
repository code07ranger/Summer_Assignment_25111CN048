#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library_data.dat"

// Structure to define book properties
typedef struct {
    int id;
    char title[100];
    char author[100];
    int is_issued; // 0 = Available, 1 = Issued
} Book;

// Function Prototypes
void displayMenu();
void addBook();
void viewBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: 
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default: 
                printf("\n[!] Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Displays the primary menu layout
void displayMenu() {
    printf("\n=================================");
    printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
    printf("\n=================================");
    printf("\n1. Add a New Book");
    printf("\n2. View All Books");
    printf("\n3. Search for a Book");
    printf("\n4. Issue a Book");
    printf("\n5. Return a Book");
    printf("\n6. Delete a Book");
    printf("\n7. Exit Program");
    printf("\n=================================\n");
}

// Appends a new book record to the file
void addBook() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("\n[!] Error opening database file.\n");
        return;
    }

    Book newBook;
    newBook.is_issued = 0; // New books are available by default

    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Strip newline

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Strip newline

    fwrite(&newBook, sizeof(Book), 1, file);
    fclose(file);

    printf("\n[+] Book successfully added and saved!\n");
}

// Reads and prints all book records stored in the file
void viewBooks() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\n[!] No records found. Try adding a book first.\n");
        return;
    }

    Book book;
    printf("\n%-10s %-30s %-30s %-10s\n", "ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------------\n");

    while (fread(&book, sizeof(Book), 1, file) == 1) {
        printf("%-10d %-30s %-30s %-10s\n", 
               book.id, 
               book.title, 
               book.author, 
               book.is_issued ? "Issued" : "Available");
    }
    fclose(file);
}

// Finds a book by matching its unique ID
void searchBook() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\n[!] No records found.\n");
        return;
    }

    int searchId, found = 0;
    Book book;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (book.id == searchId) {
            printf("\n[+] Book Found:");
            printf("\nID: %d", book.id);
            printf("\nTitle: %s", book.title);
            printf("\nAuthor: %s", book.author);
            printf("\nStatus: %s\n", book.is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n[-] Book with ID %d not found.\n", searchId);
    }
    fclose(file);
}

// Toggles a book's status to "Issued"
void issueBook() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        printf("\n[!] No records found.\n");
        return;
    }

    int targetId, found = 0;
    Book book;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &targetId);

    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (book.id == targetId) {
            found = 1;
            if (book.is_issued == 1) {
                printf("\n[!] This book is already issued to someone else.\n");
            } else {
                book.is_issued = 1;
                // Move file pointer back to rewrite this specific record
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&book, sizeof(Book), 1, file);
                printf("\n[+] Book successfully issued!\n");
            }
            break;
        }
    }

    if (!found) printf("\n[-] Book with ID %d not found.\n", targetId);
    fclose(file);
}

// Toggles a book's status to "Available"
void returnBook() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        printf("\n[!] No records found.\n");
        return;
    }

    int targetId, found = 0;
    Book book;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &targetId);

    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (book.id == targetId) {
            found = 1;
            if (book.is_issued == 0) {
                printf("\n[!] This book is already marked as available in the library.\n");
            } else {
                book.is_issued = 0;
                // Move file pointer back to rewrite this specific record
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&book, sizeof(Book), 1, file);
                printf("\n[+] Book successfully returned to the inventory!\n");
            }
            break;
        }
    }

    if (!found) printf("\n[-] Book with ID %d not found.\n", targetId);
    fclose(file);
}

// Deletes a book record by recreating the file without the targeted ID
void deleteBook() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\n[!] No records found.\n");
        return;
    }

    // Temporary file to hold everything except the deleted record
    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("\n[!] Temporary processing error.\n");
        fclose(file);
        return;
    }

    int deleteId, found = 0;
    Book book;

    printf("\nEnter Book ID to completely delete: ");
    scanf("%d", &deleteId);

    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (book.id == deleteId) {
            found = 1; // Skip writing this book to the temporary file
        } else {
            fwrite(&book, sizeof(Book), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             // Delete old storage file
        rename("temp.dat", FILE_NAME); // Swap temp file to be the main storage file
        printf("\n[-] Book successfully deleted from inventory.\n");
    } else {
        remove("temp.dat"); // Delete temp file if nothing changed
        printf("\n[-] Book with ID %d not found.\n", deleteId);
    }
}