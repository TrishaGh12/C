/*
* Name	 : Trisha Ghosha
* Prog-18: C program to implement three-dimensional translation. Output depends upon users choice. [Use OpenGL Library]
* Dept. of Computer & System Sciences, Visva-Bharati
*/


#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void init();
void display();
void draw(float **a);
void translate(int tx,int ty,int tz);

float **input,**output;
float tx,ty,tz;
int n;

int main(int argc, char** argv)
{
	n=8;
	input = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		input[i]=(float *)calloc(3,sizeof(float));
	output = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		output[i]=(float *)calloc(3,sizeof(float));
	printf("Enter the coordinates of the 3D figure (Cube/Rectangle):\n");
	for(int i=0;i<n;i++)
	{
		printf("Enter %d vertex : ",i);
		for(int j=0;j<3;j++)
			scanf("%f",&input[i][j]);
	}
	printf("\nEnter the translation vector (Tx,Ty and Tz) : ");
	scanf("%f %f %f",&tx, &ty, &tz);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(900,900);
	glutInitWindowPosition(300,300);
	glutCreateWindow("3D TRANSLATION");
	init();
	        
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0); //set backgrond color to white
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);// Set the no. of Co-ordinates along X & Y axes and their gappings
    glEnable(GL_DEPTH_TEST);// To Render the surfaces Properly according to their depths
     
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	draw(input);
	translate(tx,ty,tz);
	draw(output);
	glFlush();
}


void draw(float **a)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

		glColor3f(1.0,0.1,0.1);//Front
		glVertex3fv(a[4]);
		glVertex3fv(a[5]);
		glVertex3fv(a[6]);
		glVertex3fv(a[7]);

	glEnd();
}

void translate(int tx,int ty,int tz)
{
	for(int i=0;i<n;i++)
	{
		output[i][0]=input[i][0]+tx;
		output[i][1]=input[i][1]+ty;
		output[i][2]=input[i][2]+tz;
	}
}

