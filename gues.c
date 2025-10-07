/*
 NAME:NEHEMIAH KIPLAGAT
 REG:PA106/G/28723/25
 DES:A PROGRAM FOR THE USER TO GUESS A NUMBER
*/
#include <stdio.h>
int main() {
    int secret_number = 15; 
    int guess;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 20. Can you guess it?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 20) {
            printf("Please enter a number between 1 and 20.\n");
            continue;
        }

        if (guess > secret_number) {
            printf("Too high!\n");
        } else if (guess < secret_number) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You've guessed the number!\n");
            break;
        }
    }

    return 0;
}