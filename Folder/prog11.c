/*----------------------------
Name-Trisha Ghosh
Prog-11
Prog name:translation
------------------------------*/

#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

int n,x1,y11,x2,y2,tx,ty,count=0;
int*a,*b;

void myInit (void)
{
	glclear(GL_COLOUR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVerter2i(x,y);
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
		count++;
		if(count==2)
		{
			glFlush();
		}
}
void translatePoint()
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=a[i]+tx;
		b[i]=b[i]+ty;
	}
}

void myDisplay(void)
{
	draw_line();
	traslatePoint();
	draw_line();
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
printf("Enter tx\n");
scanf("%d",&tx);
printf("Enter ty\n");
scanf("%d",&ty);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Translation");
myInit();

glutDisplayFunc(draw_line);
glutMainLoop();
return 0;
}