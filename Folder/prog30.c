/*--------------------------------------------
* Name	 : Trisha Ghosh
* Prog-30: C program to implement Cyrus-Beck algorithm.
------------------------------------------------*/

#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>

typedef struct
{
	float x,y;
}Point ;

void draw_Window();
void draw_line(Point P1,Point P2);
void cyrusBeck();
void display(); 
void Init();

Point *n , *ver;
Point p1 , p2 , f , w ,d;
float tl ,tu , wn ,dn ;
int e;
Point mn , op;

int main(int argc , char** argv)
{
	printf("Enter the number of edge : ");
	scanf("%d",&e);
	ver = (Point*)calloc(e,sizeof(Point));
	for(int i=0;i<e;i++)
	{
		printf("Enter the %d th vertex :",i);
		scanf("%f	%f",&ver[i].x,&ver[i].y);
	}
	
	
	printf("Enter the 1st point coordiante of the line: ");
	scanf("%f	%f", &p1.x , &p1.y );
	printf("Enter the 2nd point coordiante of the line: ");
	scanf("%f	%f", &p2.x , &p2.y);	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("END POINT GENERATING ALGORITHM");
	Init();
	glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0);
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}


void display()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);
	draw_Window();
	glColor3f(1.0,0.0,0.0);
	draw_line(p1,p2);
	glPointSize(5.0);
	cyrusBeck();
	glFlush ();
}
void draw_Window()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		for(int i=0;i<e;i++)
			glVertex2f(ver[i].x , ver[i].y);
	glEnd();
}

void draw_line(Point P1,Point P2)
{
	glBegin(GL_LINES);
		glVertex2f(P1.x,P1.y);
		glVertex2f(P2.x,P2.y);
	glEnd();
}


void cyrusBeck()
{
	int flag=0;
	float t;
	n = (Point*)calloc(e,sizeof(Point));
	for(int i=0;i<e;i++)
	{
		printf("Enter the normal of %d th edge : ",i+1);
		scanf("%f	%f" , &n[i].x , &n[i].y);
	}
	
	
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	tl = 0;
	tu = 1;
	for(int i=0;i<e;i++)
	{
		w.x = p1.x - ver[i].x;
		w.y = p1.y - ver[i].y;
		wn = w.x*n[i].x + w.y*n[i].y;
		dn = d.x*n[i].x + d.y*n[i].y;
		
		if (dn == 0)
		{
			if (wn > 0)
				i++;
			else
			{
				printf("The line is invisible.\n");
				break;
			}
		}
		else
		{
			t = -(wn/dn);
			if(dn > 0)
			{
				if(t>tl)
					tl = t;
			}
			if(dn < 0)
			{
				if(t < tu)
					tu = t;
			}
		}
	}
	
	p2.x = p1.x + d.x * tu;
	p2.y = p1.y + d.y *tu;
	p1.x = p1.x + d.x *tl;
	p1.y = p1.y + d.y *tl;
	if(tl > tu)
		printf("The line is completely invisible .\n");
	else if(tl ==0 && tu ==1)
	{
		printf("The line is completely visible .\n");
		glColor3f(0.0,1.0,1.0);
		draw_line(p1,p2);
	}
	else
	{
		printf("The line is partially visible .\n");
		glColor3f(0.0,1.0,1.0);
		draw_line(p1,p2);
	}
}