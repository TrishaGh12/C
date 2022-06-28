/*---------------------------
Name:Trisha Ghosh
Prog no-11
progname- rotation
-----------------------------*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include<math.h>

void myInit(void);
void draw_pixel(int x, int y);
void rotate();
void draw_line(void);
void myDisplay(void);

int n, x1, y11, x2, y2,count=0;
int *a, *b,fx,fy;
float angle, theta;

int main(int argc, char **argv)
{
	int i;
	printf( "Enter (n)\n");
	scanf("%d", &n);
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));

for(i=0;i<n;i++)
{
	printf("Enter x%d ",i+1);
	scanf("%d",(a+i));
	printf("Enter y%d ",i+1);
	scanf("%d",(b+i));	
}
printf( "Enter the angle of theta\n");
scanf("%f", &angle);
printf( "Enter the point(fx,fy)\n");
scanf("%d %d",&fx,&fy);

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow("Rotation");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();

return 0;
}

void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500,0.0,500);
	
}
void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void rotate()
{
	int i,j;
	
	theta=(3.14/180)*angle;
	for(i=0;i<n;i++)
	{
		a[i]=fx+((a[i]-fx)*cos(theta))-((b[i]-fy)*sin(theta));
		b[i]=fy+((a[i]-fx)*sin(theta))+((b[i]-fy)*cos(theta));
	}
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
void myDisplay(void)
{	
	draw_line();
	
	rotate();
	
	draw_line();		
}