/*----------------------------
Name-Trisha Ghosh
Prog-7
Prog name:mid point circle drawing algo
------------------------------*/

#include <stdio.h>
#include <GL/glut.h>

int X1, Y1, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+X1, y+Y1);
	glEnd();
}


void myInit (void)
{
	glclear(GL_COLOUR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
	glFlush();
}

int main(int argc, char** argv)
{	
	printf("Enter X-coordinate  \n: "); 
	scanf("%d",&X1);
	printf("Enter X-coordinate  \n:");
	scanf("%d",&Y1);
	printf("\nEnter radius : \n"); 
	scanf("%d",&r);


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Mid Point Alogrithms");
	myInit ();
	glutDisplayFunc(midPointCircleAlgo);
	
	glutMainLoop();
	
	return 0;

}