#include <stdio.h>
#include <stdlib.h>
#define INSIDE  0 // 0000
#define LEFT  1   // 0001
#define RIGHT  2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000
float xl, xr, yb ,yt;
int getcode(float xl, float xr, float yb, float yt, float x, float y){
    int code = 0;
    if(x<xl)
        code |= LEFT;
    else if(x>xr)
        code |= RIGHT;
    if(y<yb)
        code |= BOTTOM;
    else if(y>yt)
        code |= TOP;
    return code;
}
void end_points(float xl, float xr, float yb, float yt, float x1, float y1, float x2, float y2){
    int pc1 = getcode(xl, xr, yb, yt, x1, y1);
    int pc2 = getcode(xl, xr, yb, yt, x2, y2);
    printf("%d, %d\n",pc1,pc2);
    int flag=0;
    while(1){
        if((pc1|pc2)==0)
        {
                printf("completely visible\n");
                flag=1;
                break;
        }
        else if((pc1&pc2)==0)
        {
        	printf("partially invisible\n");
        	break;
        }
        else if((pc1&pc2)!=0)
        {
                printf("completely invisible\n");
                return;
        }

    printf("%f %f, %f %f\n",x1,y1,x2,y2);

    }
    printf("%f %f, %f %f\n",x1,y1,x2,y2);

}
int main()
{
    float x1, y1, x2, y2;
    float xl=-1, xr=1, yb=-1 ,yt=1;
    
    printf("Enter the four values of point\n");
    scanf("%f%f%f%f",&x1,&y1, &x2, &y2);
    end_points( xl, xr, yb ,yt, x1, y1, x2, y2);
    return 0;
}