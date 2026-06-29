//Write a program to Create ticket booking system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 20

// Structure to hold passenger booking details
struct Ticket {
    int seatNumber;
    char passengerName[50];
    int isBooked; 
};

// Function declarations
void initializeSeats(struct Ticket system[], int size);
void displaySeats(struct Ticket system[], int size);
void bookTicket(struct Ticket system[], int size);
void cancelTicket(struct Ticket system[], int size);
void viewSales(struct Ticket system[], int size, float ticketPrice);

int main() {
    struct Ticket bookingSystem[TOTAL_SEATS];
    int choice;
    const float TICKET_PRICE = 15.50; // Fixed price per ticket

    // Initialize all seats to empty
    initializeSeats(bookingSystem, TOTAL_SEATS);

    while(1) {
        printf("\n=== TICKET BOOKING SYSTEM ===\n");
        printf("1. View Seating Chart\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. View Total Sales\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch(choice) {
            case 1:
                displaySeats(bookingSystem, TOTAL_SEATS);
                break;
            case 2:
                bookTicket(bookingSystem, TOTAL_SEATS);
                break;
            case 3:
                cancelTicket(bookingSystem, TOTAL_SEATS);
                break;
            case 4:
                viewSales(bookingSystem, TOTAL_SEATS, TICKET_PRICE);
                break;
            case 5:
                printf("Thank you for using the Ticket Booking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Sets up empty seats with matching IDs at startup
void initializeSeats(struct Ticket system[], int size) {
    for(int i = 0; i < size; i++) {
        system[i].seatNumber = i + 1;
        system[i].isBooked = 0;
        strcpy(system[i].passengerName, "Empty");
    }
}

// Renders visual dashboard of all seats
void displaySeats(struct Ticket system[], int size) {
    printf("\n--- CURRENT SEATING CHART ---\n");
    printf("%-10s %-15s %-10s\n", "Seat No", "Passenger Name", "Status");
    printf("---------------------------------------\n");
    for(int i = 0; i < size; i++) {
        printf("%-10d %-15s %-10s\n", 
               system[i].seatNumber, 
               system[i].passengerName, 
               (system[i].isBooked == 1) ? "RESERVED" : "AVAILABLE");
    }
    printf("---------------------------------------\n");
}

// Allocates an available seat to a user
void bookTicket(struct Ticket system[], int size) {
    int seatNo;
    printf("\nEnter preferred seat number (1-%d): ", size);
    scanf("%d", &seatNo);

    // Validate seat number range
    if(seatNo < 1 || seatNo > size) {
        printf("Error: Invalid seat number choice!\n");
        return;
    }

    // Check if seat is already occupied
    if(system[seatNo - 1].isBooked == 1) {
        printf("Sorry, Seat %d is already reserved by %s.\n", seatNo, system[seatNo - 1].passengerName);
    } else {
        printf("Enter passenger name: ");
        char nameInput[50];
        // Clear input buffer safely and read string
        scanf(" %[^\n]s", nameInput); 
        
        // Save records
        strcpy(system[seatNo - 1].passengerName, nameInput);
        system[seatNo - 1].isBooked = 1;
        printf("Success! Seat %d has been successfully booked for %s.\n", seatNo, nameInput);
    }
}

// Reverts a reservation and frees up a seat slot
void cancelTicket(struct Ticket system[], int size) {
    int seatNo;
    printf("\nEnter the seat number to cancel reservation (1-%d): ", size);
    scanf("%d", &seatNo);

    if(seatNo < 1 || seatNo > size) {
        printf("Error: Invalid seat number choice!\n");
        return;
    }

    if(system[seatNo - 1].isBooked == 0) {
        printf("Notice: Seat %d is already empty.\n", seatNo);
    } else {
        printf("Cancellation processed! Ticket for %s (Seat %d) is canceled.\n", system[seatNo - 1].passengerName, seatNo);
        // Clear database values
        system[seatNo - 1].isBooked = 0;
        strcpy(system[seatNo - 1].passengerName, "Empty");
    }
}

// Calculates and compiles total financial earnings
void viewSales(struct Ticket system[], int size, float ticketPrice) {
    int bookedCount = 0;
    for(int i = 0; i < size; i++) {
        if(system[i].isBooked == 1) {
            bookedCount++;
        }
    }
    float totalRevenue = bookedCount * ticketPrice;
    printf("\n--- SYSTEM REVENUE SUMMARY ---\n");
    printf("Total Active Bookings: %d\n", bookedCount);
    printf("Price Per Ticket: $%.2f\n", ticketPrice);
    printf("Total Collected Earnings: $%.2f\n", totalRevenue);
}