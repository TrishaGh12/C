/*-------------------------------
Name:Trisha Ghosh
Prog no-6
progname- Draw polygon using Bresenham's line drawing algo 
---------------------------------*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include<stdlib.h>

int x1, y11, x2, y2, n;
int *a,*b;
void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void draw_line(void)
{
	int dx, dy, i, e, p;
	int incx, incy, inc1, inc2;
	int x,y;
	for(p=0;p<n;p++)
	{
		if(p==n-1)
		{
			x1=*(a+p);
			x2=*(a+0);
			y11=*(b+p);
			y2=*(b+0);
		}
		else
		{
			x1=*(a+p);
			x2=*(a+p+1);
			y11=*(b+p);
			y2=*(b+p+1);
		}
	}
	dx = x2-x1;
	dy = y2-y11;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y11) incy = -1;	
	x=x1; y=y11;
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
glFlush();

}

int main(int argc, char **argv)
{
int i; 
printf( "Enter (n)\n");
scanf("%d ", &n);

a=(int*)malloc(n*sizeof(int));
b=(int*)malloc(n*sizeof(int));

for(i=0;i<n;i++)
{
	printf("Enter x%d",i+1);	
	scanf("%d",(a+i));
	printf("Enter y%d",i+1);	
	scanf("%d",(b+i));	
}

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Bresenham's Line Drawing");
myInit();

glutDisplayFunc(draw_line);
glutMainLoop();
return 0;
}