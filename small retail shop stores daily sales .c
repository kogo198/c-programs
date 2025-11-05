#include <stdio.h>


int main() {
    FILE *file;
    char filename[] = "sales.txt";
    double transaction;
    double totalSales = 0.0;
    int transactionCount = 0;
    
    // Open the file for reading
    file = fopen(filename, "r");
    
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error \n", filename);
       
        return 1;
    }
    
    printf("Reading sales transactions\n");
    
    // Read all transactions from the file
    while (fscanf(file, "%lf", &transaction) == 1) {
        totalSales += transaction;
        transactionCount++;
        printf("Transaction %d: $%.2f\n", transactionCount, transaction);
    }
    
    // Check for reading errors
    if (!feof(file)) {
        printf("Error \n");
        fclose(file);
        return 1;
    }
    
    // Close the file
    fclose(file);
    
    // Display results
    printf("\nDaily Sales Summary:\n");
    
    printf("Total Transactions: %d\n", transactionCount);
    printf("Total Sales: $%.2f\n", totalSales);
    
    return 0;
}