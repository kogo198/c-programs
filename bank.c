/*
Name:nehemiah kiplagat
Reg:PA106/G/28723/25    
describtion:a code where a back give loan to user above 21 years with an income of 21000 and above
*/
#include <stdio.h>
int main(){
    int age;
    float income,loan;
    //user age
    printf("enter your age\n");
    scanf("%d",&age);

    //user income
    printf("enter your income\n");
    scanf("%f",&income);

    //loan amount
    printf("enter the loan amount\n");
    scanf("%f",&loan);

    //check if user is eligible for loan
    if(age>=21 && income>=21000 && loan<=5*income){
        printf("you are eligible for the loan\n");
    }
    else{
        printf("you are not eligible for the loan\n");
    }
    
    return 0;
}