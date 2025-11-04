#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_SALES 1000
#define MAX_NAME_LENGTH 50
#define FILENAME_PRODUCTS "products.dat"
#define FILENAME_SALES "sales.dat"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    int min_stock_level;
} Product;

typedef struct {
    int id;
    int product_id;
    char product_name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    float total;
    time_t timestamp;
} Sale;

typedef struct {
    Product products[MAX_PRODUCTS];
    int product_count;
    Sale sales[MAX_SALES];
    int sale_count;
    float daily_revenue;
} POSSystem;

// Function prototypes
void initializeSystem(POSSystem *system);
void saveProducts(POSSystem *system);
void loadProducts(POSSystem *system);
void saveSales(POSSystem *system);
void loadSales(POSSystem *system);
void displayMenu();
void addProduct(POSSystem *system);
void viewProducts(POSSystem *system);
void updateProduct(POSSystem *system);
void processSale(POSSystem *system);
void printReceipt(Sale *sales, int count, float total);
void viewDailyRevenue(POSSystem *system);
void generateSalesReport(POSSystem *system);
void checkLowStock(POSSystem *system);
int findProductById(POSSystem *system, int id);
int findProductByName(POSSystem *system, const char *name);

int main() {
    POSSystem system;
    initializeSystem(&system);
    
    loadProducts(&system);
    loadSales(&system);
    
    int choice;
    
    printf("=== WELCOME TO POS SYSTEM ===\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(&system);
                break;
            case 2:
                viewProducts(&system);
                break;
            case 3:
                updateProduct(&system);
                break;
            case 4:
                processSale(&system);
                break;
            case 5:
                viewDailyRevenue(&system);
                break;
            case 6:
                generateSalesReport(&system);
                break;
            case 7:
                checkLowStock(&system);
                break;
            case 8:
                saveProducts(&system);
                saveSales(&system);
                printf("Data saved successfully!\n");
                break;
            case 0:
                saveProducts(&system);
                saveSales(&system);
                printf("Thank you for using POS System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\n");
    } while(choice != 0);
    
    return 0;
}

void initializeSystem(POSSystem *system) {
    system->product_count = 0;
    system->sale_count = 0;
    system->daily_revenue = 0.0;
}

void displayMenu() {
    printf("\n=== POS SYSTEM MENU ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Process Sale\n");
    printf("5. View Daily Revenue\n");
    printf("6. Generate Sales Report\n");
    printf("7. Check Low Stock\n");
    printf("8. Save Data\n");
    printf("0. Exit\n");
}

void addProduct(POSSystem *system) {
    if(system->product_count >= MAX_PRODUCTS) {
        printf("Product limit reached! Cannot add more products.\n");
        return;
    }
    
    Product *product = &system->products[system->product_count];
    
    printf("\n=== ADD NEW PRODUCT ===\n");
    product->id = system->product_count + 1;
    
    printf("Enter product name: ");
    getchar(); // Clear input buffer
    fgets(product->name, MAX_NAME_LENGTH, stdin);
    product->name[strcspn(product->name, "\n")] = 0; // Remove newline
    
    printf("Enter price: ");
    scanf("%f", &product->price);
    
    printf("Enter quantity: ");
    scanf("%d", &product->quantity);
    
    printf("Enter minimum stock level: ");
    scanf("%d", &product->min_stock_level);
    
    system->product_count++;
    printf("Product added successfully! ID: %d\n", product->id);
}

void viewProducts(POSSystem *system) {
    int i;
    printf("\n=== PRODUCT LIST ===\n");
    printf("%-5s %-20s %-10s %-10s %-15s\n", 
           "ID", "Name", "Price", "Quantity", "Min Stock");
    printf("------------------------------------------------------------\n");
    
    for(i = 0; i < system->product_count; i++) {
        Product *p = &system->products[i];
        printf("%-5d %-20s $%-9.2f %-10d %-15d\n", 
               p->id, p->name, p->price, p->quantity, p->min_stock_level);
    }
}

void updateProduct(POSSystem *system) {
    int id, choice;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    int index = findProductById(system, id);
    if(index == -1) {
        printf("Product not found!\n");
        return;
    }
    
    Product *product = &system->products[index];
    
    printf("\nCurrent details:\n");
    printf("Name: %s\n", product->name);
    printf("Price: $%.2f\n", product->price);
    printf("Quantity: %d\n", product->quantity);
    printf("Min Stock: %d\n", product->min_stock_level);
    
    printf("\nWhat do you want to update?\n");
    printf("1. Price\n");
    printf("2. Quantity\n");
    printf("3. Minimum Stock Level\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter new price: ");
            scanf("%f", &product->price);
            break;
        case 2:
            printf("Enter new quantity: ");
            scanf("%d", &product->quantity);
            break;
        case 3:
            printf("Enter new minimum stock level: ");
            scanf("%d", &product->min_stock_level);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    printf("Product updated successfully!\n");
}

void processSale(POSSystem *system) {
    if(system->product_count == 0) {
        printf("No products available for sale!\n");
        return;
    }
    
    Sale current_sales[MAX_PRODUCTS];
    int sale_items = 0;
    float total_amount = 0.0;
    char continue_sale;
    
    printf("\n=== PROCESS SALE ===\n");
    
    do {
        int product_id, quantity;
        int index;
        
        viewProducts(system);
        printf("\nEnter product ID: ");
        scanf("%d", &product_id);
        
        index = findProductById(system, product_id);
        if(index == -1) {
            printf("Product not found!\n");
            continue;
        }
        
        Product *product = &system->products[index];
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        if(quantity > product->quantity) {
            printf("Insufficient stock! Available: %d\n", product->quantity);
            continue;
        }
        
        // Add to current sale
        Sale *sale = &current_sales[sale_items];
        sale->id = system->sale_count + sale_items + 1;
        sale->product_id = product_id;
        strcpy(sale->product_name, product->name);
        sale->quantity = quantity;
        sale->price = product->price;
        sale->total = quantity * product->price;
        sale->timestamp = time(NULL);
        
        // Update product quantity
        product->quantity -= quantity;
        
        total_amount += sale->total;
        sale_items++;
        
        printf("Added: %s x %d = $%.2f\n", product->name, quantity, sale->total);
        
        printf("Add another product? (y/n): ");
        scanf(" %c", &continue_sale);
        
    } while((continue_sale == 'y' || continue_sale == 'Y') && sale_items < MAX_PRODUCTS);
    
    if(sale_items > 0) {
        // Print receipt
        printReceipt(current_sales, sale_items, total_amount);
        
        // Save sales to system
        int i;
        for(i = 0; i < sale_items; i++) {
            if(system->sale_count < MAX_SALES) {
                system->sales[system->sale_count] = current_sales[i];
                system->sale_count++;
            }
        }
        
        system->daily_revenue += total_amount;
        printf("Sale completed! Total: $%.2f\n", total_amount);
    }
}

void printReceipt(Sale *sales, int count, float total) {
    int i;
    printf("\n=== RECEIPT ===\n");
    printf("%-20s %-10s %-10s %-10s\n", "Product", "Qty", "Price", "Total");
    printf("--------------------------------------------------\n");
    
    for(i = 0; i < count; i++) {
        printf("%-20s %-10d $%-9.2f $%-9.2f\n", 
               sales[i].product_name, sales[i].quantity, 
               sales[i].price, sales[i].total);
    }
    
    printf("--------------------------------------------------\n");
    printf("%-20s $%-30.2f\n", "TOTAL:", total);
    printf("Thank you for your business!\n");
    printf("Date: %s", ctime(&sales[0].timestamp));
}

void viewDailyRevenue(POSSystem *system) {
    printf("\n=== DAILY REVENUE ===\n");
    
    // Calculate today's revenue from sales
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    float today_revenue = 0.0;
    int today_sales = 0;
    int i;
    
    for(i = 0; i < system->sale_count; i++) {
        struct tm *sale_date = localtime(&system->sales[i].timestamp);
        if(sale_date->tm_year == today->tm_year &&
           sale_date->tm_mon == today->tm_mon &&
           sale_date->tm_mday == today->tm_mday) {
            today_revenue += system->sales[i].total;
            today_sales++;
        }
    }
    
    printf("Today's Sales: %d\n", today_sales);
    printf("Today's Revenue: $%.2f\n", today_revenue);
    printf("Total Revenue (All Time): $%.2f\n", system->daily_revenue);
}

void generateSalesReport(POSSystem *system) {
    printf("\n=== SALES REPORT ===\n");
    
    if(system->sale_count == 0) {
        printf("No sales recorded yet.\n");
        return;
    }
    
    int i;
    printf("%-5s %-20s %-10s %-10s %-15s %-20s\n", 
           "ID", "Product", "Qty", "Price", "Total", "Date");
    printf("----------------------------------------------------------------------------\n");
    
    for(i = 0; i < system->sale_count; i++) {
        Sale *s = &system->sales[i];
        printf("%-5d %-20s %-10d $%-9.2f $%-14.2f %s", 
               s->id, s->product_name, s->quantity, s->price, 
               s->total, ctime(&s->timestamp));
    }
    
    printf("\nTotal Sales: %d\n", system->sale_count);
    printf("Total Revenue: $%.2f\n", system->daily_revenue);
}

void checkLowStock(POSSystem *system) {
    printf("\n=== LOW STOCK ALERTS ===\n");
    
    int low_stock_count = 0;
    int i;
    
    for(i = 0; i < system->product_count; i++) {
        Product *p = &system->products[i];
        if(p->quantity <= p->min_stock_level) {
            printf("ALERT: %s (ID: %d) - Stock: %d, Min: %d\n", 
                   p->name, p->id, p->quantity, p->min_stock_level);
            low_stock_count++;
        }
    }
    
    if(low_stock_count == 0) {
        printf("All products have sufficient stock.\n");
    } else {
        printf("Total products with low stock: %d\n", low_stock_count);
    }
}

int findProductById(POSSystem *system, int id) {
    int i;
    for(i = 0; i < system->product_count; i++) {
        if(system->products[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findProductByName(POSSystem *system, const char *name) {
    int i;
    for(i = 0; i < system->product_count; i++) {
        if(strcmp(system->products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void saveProducts(POSSystem *system) {
    FILE *file = fopen(FILENAME_PRODUCTS, "wb");
    if(file == NULL) {
        printf("Error saving products!\n");
        return;
    }
    
    fwrite(&system->product_count, sizeof(int), 1, file);
    fwrite(system->products, sizeof(Product), system->product_count, file);
    fclose(file);
}

void loadProducts(POSSystem *system) {
    FILE *file = fopen(FILENAME_PRODUCTS, "rb");
    if(file == NULL) {
        printf("No previous product data found. Starting fresh.\n");
        return;
    }
    
    fread(&system->product_count, sizeof(int), 1, file);
    fread(system->products, sizeof(Product), system->product_count, file);
    fclose(file);
    printf("Loaded %d products.\n", system->product_count);
}

void saveSales(POSSystem *system) {
    FILE *file = fopen(FILENAME_SALES, "wb");
    if(file == NULL) {
        printf("Error saving sales!\n");
        return;
    }
    
    fwrite(&system->sale_count, sizeof(int), 1, file);
    fwrite(system->sales, sizeof(Sale), system->sale_count, file);
    fwrite(&system->daily_revenue, sizeof(float), 1, file);
    fclose(file);
}

void loadSales(POSSystem *system) {
    FILE *file = fopen(FILENAME_SALES, "rb");
    if(file == NULL) {
        printf("No previous sales data found. Starting fresh.\n");
        return;
    }
    
    fread(&system->sale_count, sizeof(int), 1, file);
    fread(system->sales, sizeof(Sale), system->sale_count, file);
    fread(&system->daily_revenue, sizeof(float), 1, file);
    fclose(file);
    printf("Loaded %d sales records.\n", system->sale_count);
}
