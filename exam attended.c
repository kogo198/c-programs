/*
name:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:a program that checks student eligible for final exam
*/
 #include <stdio.h>
int main(){
    float attendance, avg_marks;
    //attendance percentage
    printf("Enter attendance percentage: ");
    scanf("%f", &attendance);
    //avarage marks
    printf("Enter average marks: ");
    scanf("%f", &avg_marks);
    //condition
    if(attendance >= 75 && avg_marks >= 40){
        printf("Eligible for final exams.\n");
    } else {
        printf("Not eligible.\n");
    }
    return 0;

}
    
    return 0;
}



