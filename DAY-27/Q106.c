//Write a program to Create employee management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.txt"

// Structure to define Employee attributes
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function declarations
void addEmployee();
void viewEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    EMPLOYEE MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. View All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Update Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer(); // Clear newline character from buffer

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to safely clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a new employee record to the file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    clearBuffer();

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Write structure data safely to text file
    fprintf(fp, "%d|%s|%s|%.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// 2. Read and display all employee records
void viewEmployees() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found! Add an employee first.\n");
        return;
    }

    Employee emp;
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("------------------------------------------------------------------\n");

    // Read delimited formatting sequentially
    while (fscanf(fp, "%d|[^|]|[^|]|%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    fclose(fp);
}

// 3. Find a specific employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(fp, "%d|[^|]|[^|]|%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == searchId) {
            found = 1;
            printf("\nRecord Found:");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: %.2f\n", emp.salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Update an existing record
void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    // Create a temp file to hold modified database
    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("\nError updating files!\n");
        fclose(fp);
        return;
    }

    int updateId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &updateId);
    clearBuffer();

    while (fscanf(fp, "%d|[^|]|[^|]|%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == updateId) {
            found = 1;
            printf("\nEnter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);
        }
        fprintf(tempFp, "%d|%s|%s|%.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }

    fclose(fp);
    fclose(tempFp);

    // Swap original file with the updated temp file
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("\nRecord updated successfully!\n");
    } else {
        printf("\nEmployee with ID %d not found.\n", updateId);
    }
}

// 5. Delete an employee record
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("\nError deleting record!\n");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    while (fscanf(fp, "%d|[^|]|[^|]|%f\n", &emp.id, emp.name, emp.designation, &emp.salary) == 4) {
        if (emp.id == deleteId) {
            found = 1; // Skip writing this record to temp file
            continue;
        }
        fprintf(tempFp, "%d|%s|%s|%.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}
