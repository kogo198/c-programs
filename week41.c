/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25    
DISCRIPTION:DATA DEALS WHERE USER ENTER CHOICES FROM DISPLAYED MENU
*/
#include <stdio.h>
int main() {
    int choice;
    
    // Display menu
    printf(" select data bundle:\n");
    printf("1. 100MB @ 50 KESS\n");
    printf("2. 500MB @ 200 KESS\n");
    printf("3. 1GB @350 KESS\n");
    printf("4. 2GB @600 KESS\n");
    printf("5. 5GB @1500 KESS\n");
    printf("6. free network @2000 KESS\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    
    // Handle user choice
    switch (choice)
    {
        case 1:
            printf("You selected 100MB @ 50 KESS\n");
            break;
        case 2:
            printf("You selected 500MB @ 200 KESS\n");
            break;
        case 3:
            printf("You selected 1GB @350 KESS\n");
            break;
        case 4:
            printf("You selected 2GB @600 KESS\n");
            break;
        case 5:
            printf("You selected 5GB @1500 KESS\n");
            break;
        case 6:
            printf("You selected free network @2000 KESS\n");
            break;
        default:
            printf("Invalid choice. Please select a valid option (1-6).\n");
    }
    
    return 0;
}