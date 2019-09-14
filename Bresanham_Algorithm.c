#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

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

char buffer[20];

void plot_point(int x,int y)
{
 glColor3f(0,1,0);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 glFlush();
}



void draw()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,1.0);

glBegin(GL_LINES);


glVertex2f(400,799);
glVertex2f(400,0);
glVertex2f(799,400);
glVertex2f(0,400);

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
glFlush();   

text( 10,775, "Akansh Nirmal");
text( 10,750, "500061342");
text( 410,750," Y-Axis");
text( 700,410," X-Axis");
glEnd();
}


void pre_bresenham(int x1, int y1, int x2, int y2)
{
 if(x1<x2)
 { 
  Bresenham_algo(x1,y1,x2,y2); 
 }
 else
 { 
 Bresenham_algo(x2,y2,x1,y1);
 }
}

void Bresenham_algo(int x1, int y1, int x2, int y2)
{
 int dx,dy,Po;
 int s=0;
 dx=(x2-x1);
 dy=(y2-y1);
 
 if(dy<=dx&&dy>0)
 {
  dx=abs(dx);
  dy=abs(dy);
  Po=(2*dy)-dx;
  plot_point(x1,y1);
  int xk=x1;
  int yk=y1;
  for(s=x1;s<x2;s++)
  { 
   if(Po<0)
   {	
    xk++;
	plot_point(xk,yk);
	Po=Po+(2*dy);
   }
   else
   {
	xk++;
	yk++;
	plot_point(xk,yk);
	Po=Po+(2*dy)-(2*dx);
   }
  }
 }
  
 else if(dy>dx&&dy>0)
 {
  dx=abs(dx);
  dy=abs(dy);
  Po=(2*dx)-dy;
  plot_point(x1,y1);
  int xk=x1; 
  int yk=y1;
  for(s=y1;s<y2;s++)
  { 
   if(Po<0)
   {
   	yk++;
	plot_point(xk,yk);
	Po=Po+(2*dx);
   }
   else
   {
	xk++;
	yk++;
	plot_point(xk,yk);
	Po=Po+(2*dx)-(2*dy);
   }
  }			
 }
 
 else if(dy>=-dx)
 {
  dx=abs(dx);
  dy=abs(dy);
  Po=(2*dy)-dx;
  plot_point(x1,y1);
  int xk=x1;
  int yk=y1;
  for(s=x1;s<x2;s++)
  { 
   if(Po<0)
   {
   	xk++;
	plot_point(xk,yk);
	Po=Po+(2*dy);
   }
   else
   {
	xk++;
	yk--;
	plot_point(xk,yk);
	Po=Po+(2*dy)-(2*dx);
   }
  }
 }
 
 else if(dy<-dx)
 {
  dx=abs(dx);
  dy=abs(dy);
  Po=(2*dy)-dx;
  plot_point(x1,y1);
  int xk=x1;
  int yk=y1;
  for(s=y1;s>y2;s--)
  { 
   if(Po<0)
   {	
	yk--;
	plot_point(xk,yk);
	Po=Po+(2*dx);
   }
   else
   {
	xk++;
	yk--;
	plot_point(xk,yk);
	Po=Po+(2*dx)-(2*dy);
   }
  }
 }
glFlush();
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
  sprintf(buffer,"X: %d, Y: %d",coordinate[0].x,coordinate[0].y);
  text(coordinate[0].x+5,coordinate[0].y-5,buffer);
 }
 if(count == 2)
 { 
 float m = ((float)coordinate[1].y-(float)coordinate[0].y)/((float)coordinate[1].x-(float)coordinate[0].x);
 sprintf(buffer,"X: %d, Y: %d, Slope = %f",coordinate[1].x,coordinate[0].y,m);
 text(coordinate[1].x+5,coordinate[1].y-5,buffer);
 pre_bresenham(coordinate[0].x, coordinate[0].y, coordinate[1].x, coordinate[1].y);
 count=0;
 }
}

void Display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 1.0);
 draw();
 glFlush();
}  

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(800,800);
 glutCreateWindow("Bresenham Algorithm");
 glutDisplayFunc(Display);
 glutMouseFunc(Mouse);
 myInit();
 glutMainLoop();
 return 0;
}
