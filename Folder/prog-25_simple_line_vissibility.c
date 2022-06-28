/*
* Name	 : Trisha Ghosh
* Prog-25: C program to implement simple visibility algorithm for a straight line.
* Dept. of Computer & System Sciences, Visva-Bharati
*/

#include <stdio.h>
#include<GL/glut.h>

void myInit();
void display();
void drawPolygon();
void visibility();

float xl,xr,yb,yt,Xa,Xb,Ya,Yb;

int main(int argc , char** argv)
{
	
	
	printf("Enter the point of the straight line: \n");    
	printf("Enter the starting point: \n");    
	scanf("%f%f",&Xa,&Ya);
	printf("Enter the ending point: \n");    
	scanf("%f%f",&Xb,&Yb);
	
	printf("Enter the points of the Window:\n");
	printf("Enter Left: \n");    
	scanf("%f",&xl);
	printf("Enter Right: \n");    
	scanf("%f",&xr);
	printf("Enter Bottom: \n");    
	scanf("%f",&yb);
	printf("Enter Top: \n");    
	scanf("%f",&yt);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Simple line visibility algorithm " );
	myInit();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;

}
void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
	
	glTranslatef(600/2.0, 600 / 2.0, 0); // to put the orgin(0,0) at the center of the window
	
}
void display()
{
	glClear (GL_COLOR_BUFFER_BIT);
	drawPolygon();
	visibility();
	glFlush ();
}
void drawPolygon()
{
	
	glColor3f(1.0, 1.0, 1.0);
	// drawing the window 
	glBegin(GL_POLYGON);
	glVertex2f(xl,yb);
	glVertex2f(xl,yt);
	glVertex2f(xr,yt);
	glVertex2f(xr,yb);

	glEnd();
	
	// drawing the line
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(Xa,Ya);
	glVertex2f(Xb,Yb);

	glEnd();
	
}

void visibility()
{
	if ((Xa < xl && Xb < xl) || ( Xa > xr && Xb > xr) || (Ya < yb && Yb < yb) || (Ya > yt && Yb > yt))
		printf("The line is completely invisible .\n");
	else
	{
		if((Xa < xl || Xa > xr) || (Xb < xl || Xb > xr) || (Ya < yb || Ya > yt) || (Yb < yb || Yb > yt))
			printf("The line is partially visible .\n");
		else
			printf("The line is completely visible.\n");
	}
}

