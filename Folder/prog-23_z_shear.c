/*
* Name	 : Trisha Ghosh
* Prog-23: C program to implement z-axis shearing of an object in three-dimension. Output depends upon user’s choice. [Use OpenGL Library]
* Dept. of Computer & System Sciences, Visva-Bharati
*/


#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define n 8

void display();
void init();
void ShearZ();
void Axes(void);
void draw(float **a);
float **input,**output;
float Shx,Shy,Shz,Zref;

int main(int argc, char** argv)
{
	printf("IMPLEMENTING 3D TRANSLATION FOR QUADS........\n");
	input = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		input[i]=(float *)calloc(3,sizeof(float));
	output = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		output[i]=(float *)calloc(3,sizeof(float));
	printf("Enter the coordinates of the 3D figure:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			scanf("%f",&input[i][j]);
	printf("Enter the Shearing factors:\n");
	scanf("%f %f %f",&Shx, &Shy, &Shz);
	printf("Enter the Z-Reference Value:\n");
	scanf("%f",&Zref);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1362,750);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D REFLECTION");
	init();
	        
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void init()
{
    	glClearColor(0.0,0.0,0.0,0.0);
    	glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);// Set the no. of Co-ordinates along X & Y axes and their gappings
    	glEnable(GL_DEPTH_TEST);// To Render the surfaces Properly according to their depths
}
void ShearZ()
{
	for(int i=0;i<n;i++)
	{
		output[i][0]=input[i][0]+(input[i][2]-Zref)*Shx;
		output[i][1]=input[i][1]+(input[i][2]-Zref)*Shy;
		output[i][2]=input[i][2];
	}
}
void Axes(void)
{
	 glColor3f (1.0, 1.0, 1.0);               // Set the color to BLACK
	 glBegin(GL_LINES);                       // Plotting X-Axis
	 glVertex2s(-1000 ,0);
	 glVertex2s( 1000 ,0);
	 glEnd();
	 glBegin(GL_LINES);                       // Plotting Y-Axis
	 glVertex2s(0 ,-1000);
	 glVertex2s(0 , 1000);
	 glEnd();
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
void display()
{
	int choice;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	Axes();
	draw(input);
	ShearZ();
	draw(output);
	glFlush();
}	
