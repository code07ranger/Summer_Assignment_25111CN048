//Write a program to Create contact management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"

// Structure to hold contact details
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void editContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        printf("\n--- Contact Management System ---\n1. Add\n2. Display\n3. Search\n4. Edit\n5. Delete\n6. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) { clearInputBuffer(); continue; }
        clearInputBuffer();
        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to add a new contact
void addContact() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) return;
    Contact c;
    printf("Enter Name: "); fgets(c.name, 50, stdin); c.name[strcspn(c.name, "\n")] = 0;
    printf("Enter Phone: "); fgets(c.phone, 20, stdin); c.phone[strcspn(c.phone, "\n")] = 0;
    printf("Enter Email: "); fgets(c.email, 50, stdin); c.email[strcspn(c.email, "\n")] = 0;
    fprintf(fp, "%s,%s,%s\n", c.name, c.phone, c.email);
    fclose(fp);
    printf("Contact added!\n");
}

// Function to display all contacts
void displayContacts() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) { printf("No contacts.\n"); return; }
    char line[150];
    printf("\nName | Phone | Email\n");
    while (fgets(line, sizeof(line), fp)) printf("%s", line);
    fclose(fp);
}

// Function to search, edit, or delete a contact (using temporary file)
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;
    char name[50], line[150], search[50];
    printf("Enter name to search: "); fgets(search, 50, stdin); search[strcspn(search, "\n")] = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search)) printf("Found: %s", line);
    }
    fclose(fp);
}

// Simple edit/delete functions would follow similar file-handling logic as search.
void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}