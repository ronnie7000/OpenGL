#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
 
void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);  
}

void myInit()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

typedef struct
{
 GLint x;
 GLint y;
} GLPOINT;

void plot_point(int x,int y)
{
 glColor3f(1,0,0);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 glFlush();
}

int round(float num)
{
 int val = (int)num;
 float diff = num-(val*1.0);
 if(diff <0.5)
  return val;
 else
  return val+1;         
}

float m;

void DDA(int x1,int y1,int x2,int y2) 
{ 
 float dy = y2-y1;
 float dx = x2-x1;
 m = dy/dx; 
   
 if(m>0) 
 {
  if(abs(m)<=1)
  {
   float yk = y1*1.0;
   int i=x1;
   for(;i<=x2;i++)
   {
    int ry = round(yk);
    plot_point(i,ry);
    yk = yk + m;
   }
  }
  else 
  {
   float xk = x1*1.0;
   int i=y1;
   float res = (1/m);
   for(;i<=y2;i++)
   {
    int rx = round(xk);
    plot_point(rx,i);
    xk = xk+ res;
   }
  
  }
}
else
{
 if(abs(m) <=1)  
 {
  float yk = y1*1.0;
  int i=x1;
  for(;i<=x2;i++)
  {
   int ry = round(yk);
   plot_point(i,ry);
   yk = yk + m;
  }
  }
 else 
 {
  float xk = x1*1.0;
  int i=y1;
  float res = (1/m);
  for(;i>=y2;i--)
  {
   int rx = round(xk);
   plot_point(rx,i);
   xk = xk-res;
  }
 }
}
}

void draw(int x1,int y1,int x2,int y2)
{  
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,1.0);
glBegin(GL_LINES);

glVertex2f(400,799);
glVertex2f(400,0); 
glVertex2f(0,400);
glVertex2f(799,400);

glVertex2f(400,799);
glVertex2f(410,784);
glVertex2f(400,799);
glVertex2f(390,784);

glVertex2f(400,0);
glVertex2f(410,10);
glVertex2f(400,0);
glVertex2f(390,10);

glVertex2f(0,400);
glVertex2f(10,410);
glVertex2f(0,400);
glVertex2f(10,390);

glVertex2f(799,400);
glVertex2f(789,390);
glVertex2f(799,400);
glVertex2f(789,410);


glEnd();   

text( 10,775, "Akansh Nirmal");
text( 10,750, "500061342");
text( 410,750," Y-Axis");
text( 700,410," X-Axis");

 if(x1 <= x2)
 {
  DDA(x1,y1,x2,y2);
 }
 else
 {
  DDA(x2,y2,x1,y1);
 }
}

void Mouse(int button,int state,int x,int y)
{	
 static int count;
 static GLPOINT coordinate[2];
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 {
  coordinate[count].x = x;
  coordinate[count].y = 800 - y;
  count++;
 }
 if(count == 2)
 { draw(coordinate[0].x, coordinate[0].y, coordinate[1].x, coordinate[1].y);
   count=0; }
}

void Display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 1.0);
 glFlush();
}
 
int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(800,800);
 glutCreateWindow("DDA Algorithm");
 glutDisplayFunc(Display);
 glutMouseFunc(Mouse);
 myInit();
 glutMainLoop();
 return 0;
}
