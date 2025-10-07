/*
name:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:a program that checks student eligible for final exam
*/
#include <stdio.h>
int main() {
    int attendance, average;
    
    // Input attendance and avarage marks
    printf("Enter number of classes attended : ");
    scanf("%d", &attendance);
    printf("Enter number you avarage marks: ");
    scanf("%d", &average);
    
    // Check eligibility
    if (attendance >= 70% && avarage  >= 40) {
        printf("Eligible for final exam.\n");
    } else {
        printf("Not eligible for final exam.\n");
    }
    
    return 0;
}


