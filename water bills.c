/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:a program to promp user to enter number of water units comsumed with use of if_else if_else
*/
#include <stdio.h>
int main() {
    int units;
    float total_bill;

    // Prompt the user to enter the number of water units consumed
    printf("Enter the number of water units consumed: ");
    scanf("%d", &units);

    // Calculate the total bill based on consumption rules
    if (units <= 30) {
        total_bill = units * 20.0;
    } else if (units <= 60) {
        total_bill = (30 * 20.0) + ((units - 30) * 25.0);
    } else {
        total_bill = (30 * 20.0) + (30 * 25.0) + ((units - 60) * 30.0);
    }

    // Display the total bill in KES with two decimal places
    printf("Total bill: KES %.2f\n", total_bill);

    return 0;
}

