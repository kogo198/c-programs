#include <stdio.h>

// Define structure to hold student information
struct Student {
    char name[50];
    int registrationNumber;
    float totalMarks;
};

int main() {
    // Define structure variable
    struct Student student;
    FILE *file;
    
    // Open the binary file for reading
    file = fopen("C:\\Users\\Administrator\\Desktop\\c program\\results.dat", "rb");
    
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error: Could not open results.dat file.\n");
        return 1;
    }
    
    printf("Student Examination Results:\n");
    
    // Read and display all student records
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        printf("Name: %s\n", student.name);
        printf("Registration Number: %d\n", student.registrationNumber);
        printf("Total Marks: %.2f\n", student.totalMarks);
        
    }
    
    // Close the file
    fclose(file);
    
    return 0;
}