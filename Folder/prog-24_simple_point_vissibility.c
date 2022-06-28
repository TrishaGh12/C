/*
* Name	 : Trisha Ghosh
* Prog-24: C program to implement point visibility algorithm.
* Dept. of Computer & System Sciences, Visva-Bharati
*/

#include <stdio.h>
#include<GL/glut.h>

void myInit();
void display();
void drawPolygon();
void visibility();

float xl,xr,yb,yt,x,y;

int main(int argc , char** argv)
{
	
	
	printf("Enter the point: \n");    
	scanf("%f%f",&x,&y);
	
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
	glutCreateWindow("Simple point visibility algorithm " );
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
	glBegin(GL_POLYGON);
	glVertex2f(xl,yb);
	glVertex2f(xl,yt);
	glVertex2f(xr,yt);
	glVertex2f(xr,yb);

	glEnd();
	
	// drawing the point 
	glBegin(GL_POINTS);

	glColor3f(1.0,0.0,0.0);
	glVertex2d(x,y);

	glEnd();
	
}

void visibility()
{
	if ((x>= xl && x<= xr) && (y>=yb  && y <= yt)) //vissible
		printf("The point is visible .\n");
	else
		printf("The point is not visible.\n");
}

