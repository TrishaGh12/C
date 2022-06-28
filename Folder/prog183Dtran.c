/*--------------------------
Name:Trisha Ghosh
Prog:18
ProgName:3D translation
----------------------------*/

#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define n1 8
#define n2 3

float tx,ty,tz,**input,**output,**a;

void init();
void translate(int tx,int ty,int tz);
void draw(float **a);
void display();

int main(int argc, char** argv)
{
	printf("------------------------------------");
	
	input=(float**)calloc(n1,sizeof(float*));
        output=(float**)calloc(n1,sizeof(float*));
        a=(float**)calloc(n1,sizeof(float*));
        for(int i=0;i<n1;i++)
        {
       	input[i]=(float*)calloc(n2,sizeof(float));
       	output[i]=(float*)calloc(n2,sizeof(float));
       	a[i]=(float*)calloc(n2,sizeof(float));
       }
       printf("Enter the elements of 3D transformation:\n");
       for(int i=0;i<n1;i++)
       {
       	for(int j=0;j<n2;j++)
       	{
       	   	scanf("%f",&input[i][j]);
       	}
       }
    	printf("Enter Tx,Ty &Tz: \n");
        scanf("%f %f %f",&tx,&ty,&tz);
	    glutInit(&argc,argv);
	    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	    glutInitWindowSize(1362,750);
	    glutInitWindowPosition(0,0);
	    glutCreateWindow("3D TRANSFORMATIONS");
	    init();
    
        glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void init()
{
	glClearColor(1.0,1.0,1.0,1.0); 
	glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
	glEnable(GL_DEPTH_TEST);
}
void translate(int tx,int ty,int tz)
{
	for(int i=0;i<8;i++)
	{
		output[i][0]=input[i][0]+tx;
		output[i][1]=input[i][1]+ty;
		output[i][2]=input[i][2]+tz;
	}
}
void Axes(void)
{
		 glColor3f (0.0, 0.0, 0.0);              
		 glBegin(GL_LINES);                      
		 glVertex2s(-1000 ,0);
		 glVertex2s( 1000 ,0);
		 glEnd();
		 glBegin(GL_LINES);                      
		 glVertex2s(0 ,-1000);
		 glVertex2s(0 , 1000);
		 glEnd();
}
void draw(float **a)
{
	glBegin(GL_QUADS);
	glColor3f(0.7,0.4,0.5); //behind
	glVertex3fv(a[0]);
	glVertex3fv(a[1]);
	glVertex3fv(a[2]);
	glVertex3fv(a[3]);
	
	glColor3f(0.8,0.2,0.4);  //bottom
	glVertex3fv(a[0]);
	glVertex3fv(a[1]);
	glVertex3fv(a[5]);
	glVertex3fv(a[4]);
	
	glColor3f(0.3,0.6,0.7); //left
	glVertex3fv(a[0]);
	glVertex3fv(a[4]);
	glVertex3fv(a[7]);
	glVertex3fv(a[3]);

	glColor3f(0.2,0.8,0.2);  //right
	glVertex3fv(a[1]);
	glVertex3fv(a[2]);
	glVertex3fv(a[6]);
	glVertex3fv(a[5]);

	glColor3f(0.7,0.7,0.2); //up
	glVertex3fv(a[2]);
	glVertex3fv(a[3]);
	glVertex3fv(a[7]);
	glVertex3fv(a[6]);

	glColor3f(1.0,0.1,0.1);
	glVertex3fv(a[4]);
	glVertex3fv(a[5]);
	glVertex3fv(a[6]);
	glVertex3fv(a[7]);

	glEnd();
}

void display()
{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		Axes();
		glColor3f(1.0,0.0,0.0);
		draw(input);
		translate(tx,ty,tz);
		draw(output);
		glFlush();
}