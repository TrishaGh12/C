/*---------------------------------
 Name	 : Trisha Ghosh
 Prog-14: C program to implement two-dimensional reflection with respect to a pivot point. 
 Output depends upon user’s choice. [Use OpenGL Library]
-----------------------------------*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void myInit();
void draw_pixel(int, int);
void draw_polygon(void);
void translate(void);
void pivot_reflect(void);
void display(void);

int n,*a,*b,tx,ty,count=0;

int main(int argc, char **argv)
{
	int i;
	//inputs
	printf("Enter the number of sides:\n");
	scanf("%d", &n);

	printf("\nEnter Points (x,y):\n");
	//allocate arrays
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("\nEnter x%d: ",i+1);
		scanf("%d",(a+i));				//scan x
		printf("\nEnter y%d: ",i+1);
		scanf("%d",(b+i));				//scan y
	}
	printf("Enter the pivot points:\n");
	printf("Enter pivot_x: \n");
	scanf("%d", &tx);
	printf("Enter pivot_y: \n");
	scanf("%d", &ty);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D-Transformation-Reflection");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glClear(GL_COLOR_BUFFER_BIT);
}

void draw_pixel(int x, int y)
{
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void display()
{
	draw_polygon();		//original position
	tx=-tx;
	ty=-ty;
	translate();		//translate to midpoint
	pivot_reflect();
	tx=-tx;
	ty=-ty;
	translate();		//translate to pivot point
	draw_polygon();		//reflected position
}

void draw_polygon(void)
{
	int dx, dy, i, p, e, incx, incy, inc1, inc2, x, y,x1,x2,y11,y2;
	for(p=0;p<n;p++)
	{
		if(p==n-1)		//for last point
		{
			x1=*(a+p);
			x2=*(a+0);
			y11=*(b+p);
			y2=*(b+0);
		}
		else			//for all other point
		{
			x1=*(a+p);
			x2=*(a+p+1);
			y11=*(b+p);
			y2=*(b+p+1);
		}
		dx = x2-x1;
		dy = y2-y11;
		if (dx < 0) dx = -dx;
		if (dy < 0) dy = -dy;
		incx = 1;
		if (x2 < x1) incx = -1;
		incy = 1;
		if (y2 < y11) incy = -1;
		x = x1; y = y11;
		if (dx > dy)
		{
			draw_pixel(x, y);
			e = 2 * dy-dx;
			inc1 = 2*(dy-dx);
			inc2 = 2*dy;
			for (i=0; i<dx; i++)
			{
				if (e >= 0)
				{
					y += incy;
					e += inc1;
				}
				else
					e += inc2;
				x += incx;
				draw_pixel(x, y);
			}
		}
		else
		{
			draw_pixel(x, y);
			e = 2*dx-dy;
			inc1 = 2*(dx-dy);
			inc2 = 2*dx;
			for (i=0; i<dy; i++)
			{
				if (e >= 0)
				{
					x += incx;
					e += inc1;
				}
				else
					e += inc2;
				y += incy;
				draw_pixel(x, y);
			}
		}
	}
	count++;
	if(count==2)
	{
		glFlush();
	}
}

void translate()
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=a[i]+tx;
		b[i]=b[i]+ty;
	}
}

void pivot_reflect()
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=-a[i];
		b[i]=-b[i];
	}
}