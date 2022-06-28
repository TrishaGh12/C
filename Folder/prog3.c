/*--------------------------
Name:Trisha Ghosh
Prog:3
ProgName:common starting starting point slop and number of iterations are given
----------------------------*/

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double x1,y12,slope[2];
int step;

float round_value(float v)
{
  return floor(v + 0.5);
}
void DDA(void)
{
 
  float c;
  double x,y;
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);
  
  glVertex2d(x1,y12);
  int k,i; 
  for(i=0;i<2;i++)
  {
  	x=x1;
  	y=y12;
  	c=y-slope[i]*x;
  
  	for(k=0;k<step;k++)
  	{
		if(slope[i]<1)
  		{
  		x=x+1;
  		y=slope[i]*x+c;	
  		}
  		else if(slope[i]>1)
  		{
  		y=y+1;
  		x=(y-c)/slope[i];
  		}
  		else
  		{
  		x=x+1;
  		y=y+1;
  		}
    
  	  glVertex2d(round_value(x), round_value(y));
  	}
  }
  glEnd();

  glFlush();
}

void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{
  int i;
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&x1,&y12);
  printf("\n************************************");
  printf("\nEnter steps( step):\n");
  scanf("%d",&step);
  printf("\n************************************");
  printf("Enter slope\n");
  for(i=0;i<2;i++)
  {
  	scanf("%lf",&slope[i]);
  }
  
  glutInit(&argc,argv);
  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  
  glutCreateWindow("DDA_Line");
  
  Init();
  glutDisplayFunc(DDA);
  glutMainLoop();
}