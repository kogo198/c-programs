/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:a program to promp user to enter number of water units comsumed with use of if_else if_else
*/
#include <stdio.h>
int main() {
    int units;
    float bill;

    // Input number of water units consumed
    printf("Enter number of water units consumed: ");
    scanf("%d", &units);

    // Calculate bill based on units consumed
    if (units <= 45) {
        bill = units * 22.77; 
        // Rate for first 30 units
    } else if (units <= 100) {
        bill = (45 * 0.50) + ((units - 45) * 0.75);
         // Rate for next 70 units
    } else if (units <= 200) {
        bill = (45 * 0.50) + (70 * 0.75) + ((units - 100) * 1.20); 
        // Rate for next 100 units
    } else {
        bill = (30 * 0.50) + (70 * 0.75) + (100 * 1.20) + ((units - 200) * 1.50);
         // Rate for above 200 units
    }

    // Output the total bill
    printf("Total water bill: Ksh %.2f\n", bill);

    return 0;
}