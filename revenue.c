/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:A SIMPLE 1D C CODE FOR CALCULATING AND DOING AVARAGE REVENUE
*/
#include <stdio.h>

int main() {
    int i;
    int sum = 0;
    int revenue[7];
	int avarage_revenue

    // Ask user to input the numbers
    printf("Enter 7 revenue:\n");
    for (i = 0; i < 7; i++) {
        printf("revenue %d: ", i + 1);
        scanf("%d", &revenue[i]);
    }

    // Display and calculate the sum
    printf("\nYou entered:\n");
    for (i = 0; i < 7; i++) {
        printf("%d\n", revenue[i]);
        sum += revenue[i];
    }
	avarage_revenue=sum/7

    printf("The sum is %d\n", sum);
	printf("avarage_revenue is %d\n",avarage_revenue);

    return 0;
}
