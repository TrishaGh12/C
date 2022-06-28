/*-----------------------------------------------
* Name	 : Trisha Ghosh
* Prog-31: C program to implement Liang-Barsky .
-------------------------------------------------*/

#include<stdio.h>
#include<GL/glut.h>

void Init();
void Display();
void Liang_barsky();
int  calculation(double d , double q , double *tLower , double *tUpper);
void drawPolygon();
void drawLine(double a , double b , double c , double d);

double XL , XR , YB , YT , xa, ya , xb , yb , delX , delY ;

int main(int argc , char **argv)
{
	
    printf("Enter the XWmin , XWmax , YWmin , YWmax : ");
    scanf("%lf   %lf  %lf  %lf",&XL , &XR , &YB , &YT);

    printf("Enter the starting point of the line : ");
    scanf("%lf   %lf",&xa , &ya);
    printf("Enter the ending point of the line : ");
    scanf("%lf   %lf",&xb,&yb);
    glutInit(&argc , argv) ;
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700 , 700);
    glutInitWindowPosition(0,0);
    
    glutCreateWindow("Liang-Barsky Line Clipping Algorithm ");
    Init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}

void Init()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(0, 600, 0, 600);
}

void Display()
{
   
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawPolygon();
    glColor3f(1.0,0.0,0.0);
    drawLine(xa,ya,xb,yb);
    Liang_barsky();    
    glFlush();
}

void drawPolygon()
{
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(XL,YB);
        glVertex2f(XL,YT);
        glVertex2f(XR,YT);
        glVertex2f(XR,YB);
    glEnd();

}

void drawLine(double a , double b , double c , double d)
{
    glBegin(GL_LINES);
        glVertex2f(a,b);
        glVertex2f(c,d);
    glEnd();
}

void Liang_barsky()
{
    delX = xb - xa;
    delY = yb - ya;
    double tLower=0 , tUpper=1 , x1,Y1,x2,y2 ;
    if(calculation(-delX , (xa - XL) , &tLower ,&tUpper))
        if(calculation(delX,(XR - xa),&tLower,&tUpper))
            if(calculation(-delY , ( ya - YB) , &tLower , &tUpper))
                if(calculation(delY , (YT - ya),&tLower,&tUpper))
                {
                    if(tUpper <= 1)
                    {
                        x2 = xa + delX*tUpper;
                        y2 = ya + delY*tUpper;
                    }
                    if(tLower >= 0)
                    {
                        x1 = xa + delX*tLower;
                        Y1 = ya + delY*tLower;
                    }
                  
                    if(x1 == xa && Y1 == ya && x2 == xb && y2 == yb)
                        printf("The line is completely visible.\n");
                    else    
                        printf("The line is partially visible.\n");
                    glColor3f(0.0,1.0,1.0);
                    drawLine(x1,Y1,x2,y2);
                }
}

int calculation(double d , double q , double *tLower , double *tUpper)
{
    double t=q/d;
    if ( d == 0 && q < 0)
    {
    	printf("The line in completely invisible .\n");
        return 0;
    }
    else if(d < 0)
    {
        if ( t > *tUpper)
        {
            printf("The line in completely invisible .\n");
            return 0;
        }
        else if(t > *tLower)
            *tLower = t;
    }
    else if (d > 0)
    {
        if(t < *tLower)
        {
            printf("The line in completely invisible .\n");
            return 0;
        }
        else if(t < *tUpper)
            *tUpper = t;
    }
    return 1 ;
}