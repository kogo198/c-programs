/*
Name:nehemiah kiplagat
Reg:PA106/G/28723/25
Describtion:a code to perform the volume of a cylinder
*/
#include <stdio.h>
int main(){
    float n,r,h,v,s;
    // pi value
    n=3.142;

    //radius of the cylinder
    printf("enter the radius of the cylinder\n");
    scanf("%f",&r);

    //height of the cylinder
    printf("enter the height of the cylinder\n");
    scanf("%f",&h);

    //volume of the cylinder
    v= 2*n*r*r*h;
    s=2*n*r*r + 2*n*r*h;
    printf("the volume of the cylinder is %.2f\n",v);
    printf("the surface area of the cylinder is %.2f\n",s);
    
    return 0;
}