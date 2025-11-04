/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:program that allows the librarian to enter book titles and store 
*/
#include <stdio.h>

int main(){
	int book_borred;
	FILE *ftpr;
	ftpr =fopen("C:\\Users\\Administrator\\Desktop\\c program\\ borrowed_books.txt","rw");

	printf(" successfully stored.");
	fclose(ftpr);
	return 0;
}