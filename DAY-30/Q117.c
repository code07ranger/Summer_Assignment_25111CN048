//Write a program to Create student record system using arrays and strings.
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define DEPT_LENGTH 20

// Define the structure for a student record
struct Student {
    int roll_no;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    float gpa;
};

// Global array to store student records and a counter
struct Student records[MAX_STUDENTS];
int student_count = 0;

// Function Prototypes
void addStudent();
void displayAll();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Read choice and handle invalid integer input format safely
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to add a new student record
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: System storage is full!\n");
        return;
    }

    struct Student new_student;
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &new_student.roll_no);
    
    // Check if roll number already exists to keep data unique
    for (int i = 0; i < student_count; i++) {
        if (records[i].roll_no == new_student.roll_no) {
            printf("Error: A student with Roll Number %d already exists.\n", new_student.roll_no);
            return;
        }
    }

    // Clear input buffer before reading strings
    while (getchar() != '\n');

    printf("Enter Name: ");
    // Reads string with spaces securely, up to capacity limit
    fgets(new_student.name, NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Department: ");
    fgets(new_student.department, DEPT_LENGTH, stdin);
    new_student.department[strcspn(new_student.department, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &new_student.gpa);

    // Save the record to the array and increment count
    records[student_count] = new_student;
    student_count++;
    
    printf("Record added successfully!\n");
}

// Function to print all student data
void displayAll() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n---------------------------------------------------------------\n");
    printf("%-10s %-25s %-15s %-5s\n", "Roll No", "Name", "Department", "GPA");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-25s %-15s %-5.2f\n", 
               records[i].roll_no, 
               records[i].name, 
               records[i].department, 
               records[i].gpa);
    }
    printf("---------------------------------------------------------------\n");
}

// Function to locate a student by their Roll Number
void searchStudent() {
    if (student_count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int search_roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &search_roll);

    for (int i = 0; i < student_count; i++) {
        if (records[i].roll_no == search_roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", records[i].roll_no);
            printf("Name:        %s\n", records[i].name);
            printf("Department:  %s\n", records[i].department);
            printf("GPA:         %.2f\n", records[i].gpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", search_roll);
}