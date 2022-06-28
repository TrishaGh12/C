/*--------------------------------------------
* Name	 : Trisha Ghosh
* Prog-28: C program to implement cohen-sutherland algorithm.
-----------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

typedef struct
{
	float x , y;
	int code[4];
}Point;

void Init();
void display();
void draw_Window();
void draw_line(Point P1 , Point P2);
void line_position(Point a , Point b);
void end_point(Point *point);
void Cohen_Sutherland(Point a , Point b);
void starting_points_position();


float XL , XR , YT , YB ;
Point p1 , p2 ;
int visibility=100 , flag1 =1, flag2=1 , incount;

int main(int argc , char **argv)
{
	printf("Enter left right bottom and top positions of the window(XL , XR , YB & YT) : ");
	scanf("%f	%f	%f	%f",&XL,&XR,&YB,&YT);
	printf("Enter the first point of the line : ");
	scanf("%f	%f",&p1.x , &p1.y);
	printf("Enter the ending point of the line : ");
	scanf("%f	%f",&p2.x,&p2.y);
	

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("COHEN-SUTHERLSND LINE CLIPPING ALGORITHM");
	Init();
	glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	glTranslatef(800/2.0, 800 / 2.0, 0);	
}
void display()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);
	draw_Window();
	glColor3f(1.0,0.0,0.0);
	draw_line(p1,p2);
	end_point(&p1);
	end_point(&p2);
	starting_points_position();
	glFlush ();
}
void draw_Window()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2f(XL,YB);
		glVertex2f(XL,YT);
		glVertex2f(XR,YT);
		glVertex2f(XR,YB);
	glEnd();
}
void draw_line(Point P1,Point P2)
{
	glBegin(GL_LINES);
		glVertex2f(P1.x,P1.y);
		glVertex2f(P2.x,P2.y);
	glEnd();
}
void end_point(Point *point)
{
	if(point->x < XL) point->code[3] = 1; else point->code[3]=0;
	if(point->x > XR) point->code[2] = 1; else point->code[2]=0;
	if(point->y < YB) point->code[1] = 1; else point->code[1]=0;
	if(point->y > YT) point->code[0] = 1; else point->code[0]=0;
}

void starting_points_position()
{
	flag1 = 1 , flag2=1;

	for(int i=0;i<4;i++)
	{
		if(p1.code[i]!=0)
			flag1 =0;
		if(p2.code[i] != 0)
			flag2 = 0;
	}
	if(flag1 == 1 && flag2 == 1)
	{
		printf("The line is completely visible .\n");
		glColor3f(0.0,1.0,1.0);
		draw_line(p1,p2);
	}
	else
	{
		for(int i=0;i<4;i++)
			if(p1.code[i]&& p2.code[i])
				incount=1;
		if(incount>0)
			printf("The line is completely invisible.\n");
		else 
			Cohen_Sutherland(p1,p2);
	}

}
void line_position(Point a , Point b)
{
	flag1 = 1 , flag2=1;
	for(int i=0;i<4;i++)
	{
		if(a.code[i]!=0)
			flag1 =0;
		if(b.code[i] != 0)
			flag2 = 0;
	}
	if(flag1 == 1 && flag2 == 1)
		visibility = 1;
	else
	{
		for(int i=0;i<4;i++)
			if(a.code[i]&& b.code[i])
				incount=1;
		if(incount>0)
			visibility=-1;
		else 
		visibility=0;
	}

}

void Cohen_Sutherland(Point a , Point b)
{
	int done = 0, plotLine = 0 , mFlag =0;
	float m;

	if(p1.x != p2.x)
		m = (p2.y - p1.y)/(p2.x - p1.x);
	else if(p1.x == p2.x)
		mFlag = 1;
	else if(p1.y == p2.y)
		mFlag = 2;
		
	while(!done)
	{
		end_point(&a);
		end_point(&b);
		
		line_position(a,b);
		if(visibility == -1)
		{
			done = 1;
			plotLine = 0;
		}
		if(visibility == 1)
			done =1;
		else if(visibility==0)
		{
			plotLine = 1;
			int temp =0;
			Point t;
			for(int i=0;i<4;i++)
				if(a.code[i] != 0)
					temp++;
			
			if(temp == 0)
			{
				t = a;
				a = b;
				b = t;
			}
			
			if(mFlag == 0)
			{
				if(a.code[3] ==1)
				{
					a.y += m*(XL -a.x);
					a.x = XL;
				}
				else if(a.code[2] ==1)
				{
					printf("hi");
					a.y += m*(XR-a.x);
					a.x = XR;
				}
				else if(a.code[1] ==1)
				{
					a.x += (1/m)*(YB-a.y);
					a.y = YB;
				}
				else if(a.code[0] == 1)
				{
					a.x += (1/m)*(YT - a.y);
					a.y = YT;
				}
			}
			else if(mFlag == 1)
			{
				if(a.code[1] ==1)
					a.y = YB;
				else if(a.code[0] == 1)
					a.y = YT;
			}
			else if(mFlag == 2)
			{
				if(a.code[3] ==1)
					a.x = XL;
				else if(a.code[0] == 1)
					a.x = XR ;
			}
			
		}
	}
	if(plotLine==1)
		{
			glColor3f(0.0,1.0,1.0);
			draw_line(a,b);
		}
}