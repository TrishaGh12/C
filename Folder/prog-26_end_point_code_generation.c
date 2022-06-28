/*
* Name	 : Trisha Ghosh
* Prog-26: C program to implement end point code generation algorithm.
* Dept. of Computer & System Sciences, Visva-Bharati
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
	float x,y;
	int code[4];
}PT;

PT setcode(PT p, float xl, float xr, float yb, float yt); //for setting the 4 bit code


int main()
{
	PT p;
	int i;
	float xl,xr,yb,yt;
	
	printf("Enter the point: \n");    
	scanf("%f%f",&p.x,&p.y);
	
	printf("Enter the points of the Window:\n");
	printf("Enter Left: \n");    
	scanf("%f",&xl);
	printf("Enter Right: \n");    
	scanf("%f",&xr);
	printf("Enter Bottom: \n");    
	scanf("%f",&yb);
	printf("Enter Top: \n");    
	scanf("%f",&yt);
	

	p=setcode(p, xl,xr,yb,yt);
	
	printf("\nEnd Point Code for the given point is: ");
	for(i=0;i<4;i++)
		printf("%d ",p.code[i]);
		
	printf("\n");

	return 0;

}

PT setcode(PT p, float xl, float xr, float yb, float yt) //for setting the 4 bit code
{
	PT ptemp;

	if(p.y>yt)
		ptemp.code[0]=1; //Top
	else
		ptemp.code[0]=0;
	if(p.y<yb)
		ptemp.code[1]=1; //Bottom
	else
		ptemp.code[1]=0;
	if(p.x>xr)
		ptemp.code[2]=1; //Right
	else
		ptemp.code[2]=0;
	if(p.x<xl)
		ptemp.code[3]=1; //Left
	else
		ptemp.code[3]=0;

	ptemp.x=p.x;
	ptemp.y=p.y;

	return(ptemp);
}


