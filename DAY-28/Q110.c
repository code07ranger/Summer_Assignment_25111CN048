//Write a program to Create bank account system.
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to hold account details
typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

// Array to store multiple bank accounts
Account bank[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function Prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
int findAccountIndex(int accNum);

int main() {
    int choice;

    // Loop to display the interactive menu system
    do {
        printf("\n=== BANK ACCOUNT MANAGEMENT SYSTEM ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nThank you for using our banking system!\n");
                break;
            default:
                printf("\nInvalid selection. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new unique account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nSystem error: Maximum account capacity reached.\n");
        return;
    }

    int accNum;
    printf("\nEnter a unique Account Number: ");
    scanf("%d", &accNum);

    // Validate if the account number already exists
    if (findAccountIndex(accNum) != -1) {
        printf("Error: This account number already exists.\n");
        return;
    }

    bank[totalAccounts].accountNumber = accNum;

    printf("Enter Account Holder Name: ");
    // Clear input buffer safely before taking string entry
    while ((getchar()) != '\n'); 
    fgets(bank[totalAccounts].name, sizeof(bank[totalAccounts].name), stdin);
    bank[totalAccounts].name[strcspn(bank[totalAccounts].name, "\n")] = '\0'; // Remove newline

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &bank[totalAccounts].balance);

    if (bank[totalAccounts].balance < 0) {
        printf("Error: Initial deposit cannot be negative. Setting balance to $0.00.\n");
        bank[totalAccounts].balance = 0.0;
    }

    printf("\nSuccess: Account created successfully for %s!\n", bank[totalAccounts].name);
    totalAccounts++;
}

// Function to deposit money into a specific account
void depositMoney() {
    int accNum, index;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccountIndex(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Amount to Deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    bank[index].balance += amount;
    printf("\nSuccess: Deposited $%.2lf. New Balance: $%.2lf\n", amount, bank[index].balance);
}

// Function to withdraw money safely from an account
void withdrawMoney() {
    int accNum, index;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccountIndex(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Amount to Withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }

    // Overdraft protection logic
    if (amount > bank[index].balance) {
        printf("Error: Insufficient funds. Your current balance is $%.2lf\n", bank[index].balance);
        return;
    }

    bank[index].balance -= amount;
    printf("\nSuccess: Withdrew $%.2lf. Remaining Balance: $%.2lf\n", amount, bank[index].balance);
}

// Function to lookup and display account balance
void checkBalance() {
    int accNum, index;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccountIndex(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("\n--- Account Information ---\n");
    printf("Account Number: %d\n", bank[index].accountNumber);
    printf("Account Holder: %s\n", bank[index].name);
    printf("Current Balance: $%.2lf\n", bank[index].balance);
}

// Helper utility function to look up an account by its unique number
int findAccountIndex(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            return i; // Returns the index inside the bank memory array
        }
    }
    return -1; // Returns -1 if no matching account is found
}