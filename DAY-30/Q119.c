//Write a program to Create mini employee management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Structure defining the data of the employees
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n   EMPLOYEE MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Employee Record");
        printf("\n2. View All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Clears residual character formatting errors in input buffers
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a new employee record and append it to the file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError: Cannot open file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    clearInputBuffer();

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline character

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee record added successfully!\n");
}

// 2. Read and print all records inside the persistent storage file
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found! Add an employee first.\n");
        return;
    }

    Employee emp;
    printf("\n-------------------------------------------------------------------");
    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n-------------------------------------------------------------------");

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("\n%-10d %-20s %-20s $%-9.2f", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("\n-------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for a specific record by matching Employee ID 
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == searchId) {
            found = 1;
            printf("\nRecord Found:");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: $%.2f\n", emp.salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Locate an existing record and overwrite updated values in-place
void modifyEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == targetId) {
            found = 1;
            clearInputBuffer();

            printf("\nEnter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            // Move the file pointer back to the start of this specific record
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}

// 5. Delete records using a temporary file transfer mechanism
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError creating temporary file!\n");
        fclose(fp);
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        // Write everything to the temp file EXCEPT the target record
        if (emp.id == targetId) {
            found = 1;
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    // Swap files to complete deletion
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
}