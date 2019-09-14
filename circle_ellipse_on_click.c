#include <GL/glut.h>
#include <math.h>
#include<stdio.h>

void myInit()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glPointSize(1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void triangle(int x, int y)
{
 text(x+20,y+25,"T");	
 glBegin(GL_LINE_LOOP);
 glColor3f(0.0,1.0,0.0);
 glVertex2f(x,y);
 glVertex2f(x+25,y+50);
 glVertex2f(x+50,y);
 glEnd();
}

void square(int x,int y)
{
 text(x+25,y+25,"S");
 glBegin(GL_LINE_LOOP);
 glColor3f(1.0,1.0,0.0);
 glVertex2f(x,y);
 glVertex2f(x+50,y);
 glVertex2f(x+50,y+50);
 glVertex2f(x,y+50);
 glEnd();
}

int erad = 30;

void ellipse_midpoint(float x, float y, float a, float b, int segments) 
{ 
 text(x,y,"E");
 float theta = 2 * 3.1415926 / segments; 
 float cos = cosf(theta);
 float sin = sinf(theta);
 float x1 = 1;
 float y1 = 0;
 float t; 
 int i;
 glBegin(GL_LINE_LOOP); 
 for(i = 0; i < segments; i++) 
 {
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f((x1 * a) + x, (y1 * b) + y);
  t = x1;
  x1 = (cos * x1) - (sin * y1);
  y1 = (sin * t) + (cos * y1);
 } 
 glEnd(); 
}

int crad = 40;

void plot_point(int x, int y, int X, int Y)
{
 glBegin(GL_POINTS);
 glColor3f(0.0,0.0,1.0);
 glVertex2i(x+X, y+Y);
 glEnd();
}

void circle_midpoint(int X, int Y)
{
 text(X,Y,"C"); 
 int x = 0;
 int y = crad;
 float d = crad;
 plot_point(x,y,X,Y);
 
 while(y > x)
 {
  if(d < 0)
  {
   x++; 
   d += 2*x+1;
  }
  else
  {
   y--;
   x++;
   d += 2*(x-y)+1;
  }
  plot_point(x, y, X, Y);
  plot_point(x, -y, X, Y);
  plot_point(-x, y, X, Y);
  plot_point(-x, -y, X, Y);
  plot_point(y, x, X, Y);
  plot_point(-y, x, X, Y);
  plot_point(y, -x, X, Y);
  plot_point(-y, -x, X, Y);
 }
}

void display()
{
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

text( 10,775, "Akansh Nirmal");
text( 10,750, "500061342");
text( 410,750," Y-Axis");
text( 700,410," X-Axis");
glFlush();
}

void mouse(int button, int state, int x, int y)
{
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x<400 && y<400)
 {
  circle_midpoint(x, 800-y);
 }
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>=400 && y<400) 
 {
  ellipse_midpoint(x, 800-y, 100, 50, 100);
 }
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x<400 && y>=400)
 {
  square(x, 800-y);
 }
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>=400 && y>=400) 
 {
  triangle(x, 800-y);
 } 
glutPostRedisplay();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (800, 800);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("Circle/Ellipse Midpoint Algorithm");
 glutDisplayFunc(display);
 glutMouseFunc(mouse);
 myInit();
 glutMainLoop();
 return 0;    
}

