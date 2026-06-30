//Write a program to Create inventory management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.dat"

// Structure to hold product details
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Global pointers and counters for dynamic memory management
Product *inventory = NULL;
int product_count = 0;
int capacity = 0;

// Function Prototypes
void load_from_file();
void save_to_file();
void add_product();
void view_inventory();
void search_product();
void update_product();
void clear_buffer();

int main() {
    int choice;
    
    // Load existing records from disk on startup
    load_from_file();

    do {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Search Product\n");
        printf("4. Update Product Stock/Price\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_buffer();
            continue;
        }
        clear_buffer();

        switch (choice) {
            case 1: add_product(); break;
            case 2: view_inventory(); break;
            case 3: search_product(); break;
            case 4: update_product(); break;
            case 5: save_to_file(); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free dynamically allocated heap memory before exiting
    free(inventory);
    return 0;
}

// Clears the stdin input buffer to prevent looping bugs
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Loads binary data from disk into the heap array
void load_from_file() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        // File doesn't exist yet; initial allocation
        capacity = 10;
        inventory = (Product *)malloc(capacity * sizeof(Product));
        return;
    }

    // Read the total count first
    fread(&product_count, sizeof(int), 1, file);
    capacity = product_count + 10;
    inventory = (Product *)malloc(capacity * sizeof(Product));

    if (product_count > 0) {
        fread(inventory, sizeof(Product), product_count, file);
    }
    fclose(file);
}

// Commits current array memory into a binary file
void save_to_file() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) {
        printf("Error: Could not save data to file!\n");
        return;
    }

    fwrite(&product_count, sizeof(int), 1, file);
    if (product_count > 0) {
        fwrite(inventory, sizeof(Product), product_count, file);
    }
    fclose(file);
    printf("Inventory data saved successfully to %s. Goodbye!\n", FILE_NAME);
}

// Appends a new product item into the collection
void add_product() {
    // Dynamic resizing if structural boundary is met
    if (product_count >= capacity) {
        capacity *= 2;
        inventory = (Product *)realloc(inventory, capacity * sizeof(Product));
    }

    Product p;
    printf("\nEnter Product ID (Integer): ");
    scanf("%d", &p.id);
    clear_buffer();

    // Check if ID already exists
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == p.id) {
            printf("Error: Product ID %d already exists!\n", p.id);
            return;
        }
    }

    printf("Enter Product Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &p.price);
    clear_buffer();

    inventory[product_count] = p;
    product_count++;
    printf("Product '%s' added successfully!\n", p.name);
}

// Iterates and prints out all valid item objects
void view_inventory() {
    if (product_count == 0) {
        printf("\nYour inventory is completely empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Retrieves details using ID key comparison
void search_product() {
    int search_id;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &search_id);
    clear_buffer();

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == search_id) {
            printf("\nProduct Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with ID %d not found.\n", search_id);
}

// Mutates properties of an active array object
void update_product() {
    int update_id;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &update_id);
    clear_buffer();

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == update_id) {
            printf("\nCurrent Details - Name: %s | Qty: %d | Price: $%.2f\n", 
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            clear_buffer();

            printf("Product parameters updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", update_id);
}
