/*--------------------------------------------
* Name	 : Trisha Ghosh
* Prog-16: C program to implement x-direction shear of an object in two-dimension relative to a line which is parallel
* to x-axis.
----------------------------------------------*/

#include <stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>

int n,count=0;
double shearX,yref;
float *a,*b;

void myInit();
void shear();
void display();
void drawPolygon();

int main(int argc, char **argv)
{
	int i;
	
	printf("Enter the number of sides:\n");
	scanf("%d", &n);

	printf("\nEnter Points (x,y):\n");
	//allocate arrays
	a=(float *)malloc(n*sizeof(float));
	b=(float *)malloc(n*sizeof(float));
	for(i=0;i<n;i++)
	{
		printf("\nEnter x%d: ",i+1);
		scanf("%f",(a+i));				//scan x
		printf("\nEnter y%d: ",i+1);
		scanf("%f",(b+i));				//scan y
	}

    printf("Enter the shear value along x direction: \n");
    scanf("%lf", &shearX);
    printf("Enter the value of reference line parallel to the x axis: \n");
    scanf("%lf", &yref);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D-Transformation-Translation");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}

void shear()
{
    for(int i=0;i<n;i++)
    {
		a[i]=  a[i] + shearX*(b[i] - yref);
		b[i]=  b[i];
	}
}

void drawPolygon()
{
	glPointSize(2);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    int i;
    for (i=0;i<n;i++)
        glVertex2f(a[i], b[i]);

    glEnd();
    
    count++;
	if(count==2)
	{
		glFlush();
	}
}

void display()
{
    drawPolygon();
    shear();
    drawPolygon();
}

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glClear(GL_COLOR_BUFFER_BIT);
}
