/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DESCRIPTION:PASSWORD
*/
#include <stdio.h>
int main() {
    char password[20];
    do {
        printf("Enter password: ");
        scanf("%s", password);
    } while (strcmp(password, "1234") != 0);
    printf("Access Granted\n");
    return 0;
}