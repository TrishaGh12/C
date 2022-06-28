/*
* Name	 : Trisha Ghosh
* Prog-18: C program to implement three-dimensional rotation with respect to a pivot point. Output depends upon users choice. [Use OpenGL Library]
* Dept. of Computer & System Sciences, Visva-Bharati
*/

#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define n 8


void RotateX(float angle);
void RotateY(float angle);
void RotateZ(float angle);
void init();
void draw(float **a);
void display();
float **input,**output,**new_output;
float Angle;
float Co[3];

int main(int argc, char** argv)
{
	printf("IMPLEMENTING 3D TRANSLATION FOR QUADS(Cubes and Cuboids)........\n");
	input = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		input[i]=(float *)calloc(3,sizeof(float));
	output = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		output[i]=(float *)calloc(3,sizeof(float));
	new_output = (float **)calloc(n,sizeof(float *));
	for(int i=0;i<n;i++)
		new_output[i]=(float *)calloc(3,sizeof(float));
	printf("Enter the coordinates of the 3D figure:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			scanf("%f",&input[i][j]);
	printf("Enter the pivot point\n");
	for(int i=0;i<3;i++)
		scanf("%f",&Co[i]);
	printf("\nEnter the angle: \n");
	scanf("%f",&Angle);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D ROTATION");
	init();
	        
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


void init()
{
    glClearColor(0.0,0.0,0.0,0.0); //set backgrond color to white
    glOrtho(-454.0,454.0,-350.0,350.0,-350.0,350.0);// Set the no. of Co-ordinates along X & Y axes and their gappings
    //glOrtho(0.0, 600.0, 0.0, 600.0,0.0,600.0);
    glEnable(GL_DEPTH_TEST);// To Render the surfaces Properly according to their depths
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	Axes();
	glColor3f(1.0,0.0,0.0);
	int choice;
	printf("Enter your choice:\n1-Rotation about X-Axis.\n2-Rotation about Y-Axis.\n3-Rotation about Z-Axis.\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			draw(input);
			RotateX(Angle);
			draw(output);
			break;
		case 2:
			draw(input);
			RotateY(Angle);
			draw(output);
			break;
		case 3:
			draw(input);
			RotateZ(Angle);
			draw(output);
			break;
		default:
			printf("Wrong Choice\n");
	}
	glFlush();
}


void RotateX(float angle) //Parallel to x
{
	angle = angle*3.142/180;
	for(int i=0;i<n;i++)
	{
		output[i][0]=input[i][0];
		output[i][1]=Co[1]+(input[i][1]-Co[1])*round(cos(angle))-(input[i][2]-Co[2])*round(sin(angle));
		output[i][2]=Co[2]+(input[i][1]-Co[1])*round(sin(angle))+(input[i][2]-Co[2])*round(cos(angle));
	}
}
void RotateY(float angle) //Parallel to y
{
	angle = angle*3.142/180;
	for(int i=0;i<n;i++)
	{
		output[i][0]=Co[0]+(input[i][2]-Co[2])*round(sin(angle))+(input[i][0]-Co[0])*round(cos(angle));
		output[i][1]=input[i][1];
		output[i][2]=Co[2]+(input[i][2]-Co[2])*round(cos(angle))-(input[i][0]-Co[0])*round(sin(angle));
	}
}
void RotateZ(float angle) //Parallel to z
{
	angle = angle*3.142/180;
	for(int i=0;i<n;i++)
	{
		output[i][0]=Co[0]+(input[i][0]-Co[0])*round(cos(angle))-(input[i][1]-Co[1])*round(sin(angle));
		output[i][1]=Co[1]+(input[i][0]-Co[0])*round(sin(angle))+(input[i][1]-Co[1])*round(cos(angle));
		output[i][2]=input[i][2];
	}
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

		glColor3f(1.0,0.0,1.0);//Front
		glVertex3fv(a[4]);
		glVertex3fv(a[5]);
		glVertex3fv(a[6]);
		glVertex3fv(a[7]);

	glEnd();
}
