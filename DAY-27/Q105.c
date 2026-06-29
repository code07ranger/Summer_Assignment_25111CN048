//Write a program to Create student record management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

// Structure to store student information
typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
} Student;

// Function prototypes
void add_student();
void display_students();
void search_student();
void delete_student();
void update_student();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Function to add a new student record
void add_student() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar(); // Clear newline character from buffer

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0; 

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    // Write structure data directly to file
    fprintf(fp, "%d,%s,%s,%.2f\n", s.roll_no, s.name, s.course, s.gpa);
    fclose(fp);

    printf("Record added successfully!\n");
}

// 2. Function to display all records
void display_students() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found. Add a record first.\n");
        return;
    }

    Student s;
    printf("\n%-10s %-20s %-20s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("-------------------------------------------------------------\n");

    // Read and parse comma-separated data from the file
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &s.roll_no, s.name, s.course, &s.gpa) != EOF) {
        printf("%-10d %-20s %-20s %-5.2f\n", s.roll_no, s.name, s.course, s.gpa);
    }
    fclose(fp);
}

// 3. Function to search for a specific student by Roll Number
void search_student() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int search_roll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &search_roll);

    Student s;
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &s.roll_no, s.name, s.course, &s.gpa) != EOF) {
        if (s.roll_no == search_roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", s.roll_no);
            printf("Name:        %s\n", s.name);
            printf("Course:      %s\n", s.course);
            printf("GPA:         %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Student with Roll Number %d not found.\n", search_roll);
    }
}

// 4. Function to update an existing record
void update_student() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *tempfp = fopen("temp.txt", "w");
    
    if (fp == NULL || tempfp == NULL) {
        printf("\nError opening file or no records found.\n");
        return;
    }

    int target_roll, found = 0;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &target_roll);

    Student s;
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &s.roll_no, s.name, s.course, &s.gpa) != EOF) {
        if (s.roll_no == target_roll) {
            found = 1;
            printf("\nCurrent Details: %s | %s | %.2f\n", s.name, s.course, s.gpa);
            getchar(); // Clear buffer

            printf("Enter New Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;

            printf("Enter New Course: ");
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = 0;

            printf("Enter New GPA: ");
            scanf("%f", &s.gpa);
        }
        fprintf(tempfp, "%d,%s,%s,%.2f\n", s.roll_no, s.name, s.course, s.gpa);
    }
    fclose(fp);
    fclose(tempfp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Record updated successfully!\n");
    } else {
        printf("Student with Roll Number %d not found.\n", target_roll);
    }
}

// 5. Function to delete a student record
void delete_student() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *tempfp = fopen("temp.txt", "w");

    if (fp == NULL || tempfp == NULL) {
        printf("\nError opening file or no records found.\n");
        return;
    }

    int target_roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &target_roll);

    Student s;
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &s.roll_no, s.name, s.course, &s.gpa) != EOF) {
        if (s.roll_no == target_roll) {
            found = 1; // Skip writing this record to delete it
            continue;
        }
        fprintf(tempfp, "%d,%s,%s,%.2f\n", s.roll_no, s.name, s.course, s.gpa);
    }
    fclose(fp);
    fclose(tempfp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Student with Roll Number %d not found.\n", target_roll);
    }
}