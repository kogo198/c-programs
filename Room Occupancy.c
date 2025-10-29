/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:A SIMPLE 2D C CODE FOR ROOM OCCUPACTION
*/
#include <stdio.h>
int main(){
	int i,j;
	int occupancy[5][10];
	 printf("Enter occupancy :\n");
    for (i = 0; i < 5; i++) {
    	for(j=0;j<10;j++){
        printf("occupancy %d: ", i + 1);
        scanf("%d", &occupancy[i][j]);
		}
	
	}
        
	for (i=0;i<5;i++){
		for (j=0;j<10;j++){
			printf("%d \t",occupancy[i][j]);
		}
		printf("\n");
	}
     
	
	
	return 0;

}
