/*--------------------------------

    Program Name : Write a program in C to implement two-dimensional rotation. Output depends upon user’s choice. [Use OpenGL Library]
    Name : Trisha Ghosh
-------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>


void Init();
void Draw();
void draw_pixelFirst(int x , int y); // This finction will draw the geometric shape before rotation
void draw_pixelSecond(int x , int y); // This function will draw the geometric shape after rotation
void draw_line(int x1 , int x2 , int Y1 , int Y2); // This function will help up to draw line between to specified points (x1,Y1) (x2,Y2)
void draw_circle(); // This function will help us to draw a circle
void draw_ellipse(); // This function will help us to draw a ellipse

int side , X, Y ,r , rx,ry,choice,X1,Y1,X2,Y2 ;
double **mat , Xr , Yr , theta; // Xr and Yr are the rotation parameter and theta is the angle of the rotation

int main(int argc , char **argv)
{
	printf(" Choice 1 : Line \t Choice 2 : Polygon \t Choice 3 : Circle \t Choice 4 : Ellipse . \n Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
		{
			printf("Enter the two points using which the line will be drawn :\n");
			printf("Enter the first point :");
			scanf("%d	%d",&X1,&Y1);
			printf("Enter the second point :");
			scanf("%d	%d",&X2,&Y2);
			break;			
		}
		
		case 2:
		{
			printf("Enter the number of sides you want to have in the polygon : ");
            		scanf("%d", &side);
            		mat = (double **)calloc(side, sizeof(double *));
            		for (int i = 0; i < side; i++)
                			mat[i] = (double *)calloc(2, sizeof(double));

            		printf("Enter %d points : \n", side);
            		for (int i = 0; i < side; i++)
            		{
                			printf("Enter the %d th point : ", i + 1);
                			for (int j = 0; j < 2; j++)
                    				scanf("%lf", &mat[i][j]);
            		}
            		break;	
		}
		
		case 3:
		{
			printf("Enter the coordinates of the center of the circle , (x,y) :");
			scanf("%d	%d",&X , &Y);
			printf("Enter the radius of the circle : ");
			scanf("%d",&r);
			break;
		}
		case 4 :
		{
			printf("Enter the coordinates of the center of the ellipse , (x,y) :");
			scanf("%d	%d",&X , &Y);
			printf("Enter the X radius :");
			scanf("%d",&rx);
			printf("Enter the y radius :");
			scanf("%d",&ry);
			break;
		}
	}
	
	printf("Enter the rotation parameter and the angle for rotation :\n");
	printf("Xr and Yr and theta :");
	scanf("%lf %lf %lf",&Xr , &Yr , &theta);
	glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutInitWindowSize(800,800);
            glutInitWindowPosition(100,100);
            glutCreateWindow("Rotation");
            glutDisplayFunc(Draw);
            Init();
            glutMainLoop();
            return 0;
}


void Init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,800,0,800);
	glTranslatef(800/2.0,800/2.0,0);
}


void draw_pixelFirst(int x , int y)
{
	glColor3f(1,1,0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

void draw_pixelSecond(int x , int y)
{
	glColor3f(1, 0, 0);
    	double newX =  Xr + ((x-Xr)*cos(theta*(3.14/180))) - ((y-Yr)*sin(theta*(3.14/180)));
    	double newY = Yr+((x-Xr)*sin(theta*(3.14/180))) +((y-Yr)*cos(theta*(3.14/180)));
    	glBegin(GL_POINTS);
    		glVertex2i(newX , newY);
    	glEnd();
}

void Draw()
{
	if(choice == 1)
	{
		draw_line(X1 , X2 , Y1 , Y2);
		glFlush();
	}
	else if(choice == 2)
	{
		int n = side;
    		draw_pixelFirst(0, 0);
    		draw_pixelSecond(0,0);
    		for (int i = 1; i <= n - 1; i++)
    		{
        			draw_line(mat[i - 1][0], mat[i][0], mat[i - 1][1], mat[i][1]);
    		}
    		draw_line(mat[n - 1][0], mat[0][0], mat[n - 1][1], mat[0][1]);
    		glFlush();	
	}
	else if (choice == 3)
	{
		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(1.0, 0.0, 1.0);
    		glPointSize(2.0);
		draw_circle();
    		glFlush();	
	}
	else if(choice == 4)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 0.0, 1.0);
		glPointSize(2.0);
		draw_ellipse();
		glFlush();
	}
	
}


void draw_line(int x1 , int x2 , int Y1 , int Y2)
{
	int dx, dy, i, e;
    	int incx, incy, inc1, inc2;
	int x, y;
	dx = x2 - x1;
	dy = Y2 - Y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	   	incx = 1;
	if (x2 < x1)
		incx = -1;
	incy = 1;
	if (Y2 < Y1)
		incy = -1;
	x = x1;
	y = Y1;
	if (dx > dy)
	{
	            draw_pixelFirst(x, y);
	        	draw_pixelSecond(x, y);
	        	e = 2 * dy - dx;
	        	inc1 = 2 * (dy - dx);
	        	inc2 = 2 * dy;
	        	for (i = 0; i < dx; i++)
	        	{
			if (e >= 0)
			{
		    		y += incy;
		    		e += inc1;
			}
			else
		    		e += inc2;
			x += incx;
			draw_pixelFirst(x, y);
			draw_pixelSecond(x, y);
	        	}
	}
	else
	{
	        	draw_pixelFirst(x, y);
	        	draw_pixelSecond(x, y);
	        	e = 2 * dx - dy;
	        	inc1 = 2 * (dx - dy);
	        	inc2 = 2 * dx;
	        	for (i = 0; i < dy; i++)
	        	{
			if (e >= 0)
			{
		    		x += incx;
		    		e += inc1;
			}
			else
		    		e += inc2;
			y += incy;
			draw_pixelFirst(x, y);
			draw_pixelSecond(x, y);
	        	}
	}
}


void draw_circle()
{
	int x = 0;
    	int y = r;
    	float P = 5 / 4 - r;
    	draw_pixelFirst(x, y);
    	draw_pixelSecond(x, y);

    	while (y > x)
    	{
        	if (P < 0)
        	{
            	x++;
            	P += 2 * x + 1;
        	}
        	else
        	{
            	y--;
            	x++;
            	P += 2 * (x - y) + 1;
        	}
        	// Original Points
        	draw_pixelFirst(x, y);
        	draw_pixelFirst(x, -y);
        	draw_pixelFirst(-x, y);
        	draw_pixelFirst(-x, -y);
        	draw_pixelFirst(y, x);
        	draw_pixelFirst(-y,x);
        	draw_pixelFirst(y,-x);
        	draw_pixelFirst(-y,-x);
        	
        	
        	
        	// Translated point
        	draw_pixelSecond(x, y);
    	draw_pixelSecond(x, -y);
    	draw_pixelSecond(-x, y);
    	draw_pixelSecond(-x, -y);
    	draw_pixelSecond(y, x);
    	draw_pixelSecond(-y,x);
    	draw_pixelSecond(y,-x);
    	draw_pixelSecond(-y,-x);
    }
}


void draw_ellipse()
{
	float x = 0;
    	float y = ry;
    	float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
    	float dx = 2 * (ry * ry) * x;
    	float dy = 2 * (rx * rx) * y;
    	while (dx < dy)
    	{
    
    		// Original Points
		draw_pixelFirst(X + x, Y + y);
		draw_pixelFirst(X - x, Y + y);
		draw_pixelFirst(X + x, Y - y);
		draw_pixelFirst(X - x, Y - y);
		
		// Translated Points
		draw_pixelSecond(X + x, Y + y);
		draw_pixelSecond(X - x, Y + y);
		draw_pixelSecond(X + x, Y - y);
		draw_pixelSecond(X - x, Y - y);
	        	if (p1 < 0)
	        	{
			x = x + 1;
			dx = 2 * (ry * ry) * x;
			p1 = p1 + dx + (ry * ry);
	        	}
	        	else
	        	{
			x = x + 1;
			y = y - 1;
			dx = 2 * (ry * ry) * x;
			dy = 2 * (rx * rx) * y;
			p1 = p1 + dx - dy + (ry * ry);
	        	}
    	}
    	glFlush();

    	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);

    	while (y > 0)
    	{

            	// Original Points
		draw_pixelFirst(X + x, Y + y);
		draw_pixelFirst(X - x, Y + y);
		draw_pixelFirst(X + x, Y - y);
		draw_pixelFirst(X - x, Y - y);
		
		// Translated Points
		draw_pixelSecond(X + x, Y + y);
		draw_pixelSecond(X - x, Y + y);
		draw_pixelSecond(X + x, Y - y);
		draw_pixelSecond(X - x, Y - y);
        		if (p2 > 0)
        		{
			x = x;
			y = y - 1;
			dy = 2 * (rx * rx) * y;
			p2 = p2 - dy + (rx * rx);
        		}
	        else
	        {
			x = x + 1;
			y = y - 1;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			p2 = p2 + dx - dy + (rx * rx);
	        }
    	}
    	glFlush();
}





































	
