/*-------------------------------
Name:Trisha Ghosh
Prog no-5
progname- Bresenham's x-value same y value increased Line Drawing
---------------------------------*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
int x1, y11, x2, y2, n;

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
	int dx, dy, i, e, yn, y2n, j;
	int incx, incy, inc1, inc2;
	int x,y;
	dx = x2-x1;
	dy = y2-y11;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y11) incy = -1;
	yn=y11+n;
	y2n=y2+n;
	
	for(j=0;j<=n;j++)
	{
		x=x1;
		y=y11+j;
		if(y==y11 || y==yn)
		{
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
		y=y+1;
	}
glFlush();

}

int main(int argc, char **argv)
{
printf( "Enter (x1, y1, x2, y2)\n");
scanf("%d %d %d %d", &x1, &y11, &x2, &y2);

printf("Enter n\n");
scanf("%d",&n);

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