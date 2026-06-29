//Write a program to Create salary management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "salary_records.dat"

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund Deduction
    float gross_salary;
    float net_salary;
};

// Function prototypes
void addEmployee();
void displayAllEmployees();
void searchEmployee();
void deleteEmployee();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n     SALARY MANAGEMENT SYSTEM       ");
        printf("\n====================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Slips");
        printf("\n3. Search Employee by ID");
        printf("\n4. Delete Employee Record");
        printf("\n5. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("\nThank you for using the system!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to calculate allowances and net pay
void calculateSalary(struct Employee *emp) {
    // Standard payroll assumptions
    emp->hra = emp->basic_salary * 0.20; // 20% HRA
    emp->da = emp->basic_salary * 0.40;  // 40% DA
    emp->pf = emp->basic_salary * 0.12;  // 12% PF Deduction
    
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->net_salary = emp->gross_salary - emp->pf;
}

// 1. Add a new employee record to the file
void addEmployee() {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    struct Employee emp;
    
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear newline buffer
    
    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline character

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);

    // Run automatic math calculations
    calculateSalary(&emp);

    // Save struct to file
    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// 2. Display all employee records
void displayAllEmployees() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. Please add a record first.\n");
        return;
    }

    struct Employee emp;
    printf("\n=================================================================================================");
    printf("\n%-5s %-15s %-15s %-10s %-8s %-8s %-8s %-10s %-10s", 
           "ID", "Name", "Designation", "Basic", "HRA", "DA", "PF", "Gross", "Net Pay");
    printf("\n=================================================================================================");

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        printf("\n%-5d %-15s %-15s %-10.2f %-8.2f %-8.2f %-8.2f %-10.2f %-10.2f", 
               emp.id, emp.name, emp.designation, emp.basic_salary, emp.hra, emp.da, emp.pf, emp.gross_salary, emp.net_salary);
    }
    printf("\n=================================================================================================\n");
    fclose(fp);
}

// 3. Search for a specific employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int searchId;
    int found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == searchId) {
            found = 1;
            printf("\n----- Record Found -----");
            printf("\nID:          %d", emp.id);
            printf("\nName:        %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nBasic Pay:   $%.2f", emp.basic_salary);
            printf("\nHRA (20%%):   $%.2f", emp.hra);
            printf("\nDA (40%%):    $%.2f", emp.da);
            printf("\nPF (12%%):    $%.2f", emp.pf);
            printf("\n------------------------");
            printf("\nGross Pay:   $%.2f", emp.gross_salary);
            printf("\nNet Salary:  $%.2f", emp.net_salary);
            printf("\n------------------------\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Delete an employee record
void deleteEmployee() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int deleteId;
    int found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    // Create a temporary file to clone kept entries
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError processing request.\n");
        fclose(fp);
        return;
    }

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == deleteId) {
            found = 1; // Skip writing this element to delete it
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        printf("\nRecord deleted successfully.\n");
    } else {
        remove("temp.dat");
        printf("\nEmployee ID not found.\n");
    }
}