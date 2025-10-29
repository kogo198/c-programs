/*
NAME:NEHEMIAH KIPLAGAT
REG:PA106/G/28723/25
DISCRIPTION:A SIMPLE 3D C CODE FOR Multiple Branches
*/
#include <stdio.h>
int main(){
	int i,j,k;
	int chain[3][5][10];
	int sum;
	 printf("Enter chain:\n");
    for (i = 0; i < 3; i++) {
    	for(j=0;j<5;j++){
    		for(k=0;k<5;k++){
        printf("chain %d: ", i + 1);
        scanf("%d", &chain[i][j][k]);
		}
		}
	
	}
        
	for (i=0;i<3;i++){
		for (j=0;j<5;j++){
			for(k=0;k<10;k++){
			printf("%d \t",chain[i][j][k]);
			sum += chain0
			
			[i][j][k];
			}
		}
		printf("\n");
	}
      printf("The sum is %d\n", sum);
	
	
	return 0;
}