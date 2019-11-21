#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
using namespace std;

void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

int cp[10];

int xa,ya,xb,yb,xc,yc,xd,yd;

void init() 
{ 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Beizer Curve");
 gluOrtho2D(0,800,0,800);
 //glPointSize(1.0);
 glColor3f(0.0,1.0,1.0); 
 text( 10,775, "Akansh Nirmal");
 text( 10,750, "500061342");
 text( 410,750," Y-Axis");
 text( 700,410," X-Axis");
}

void plot_point(float x,float y)
{
 glColor3f(0,1,0);
 glBegin(GL_POINTS);
 glVertex2f(x,y);
 glEnd();
 glFlush();
}

void hull()
{
 glBegin(GL_LINES);
 glColor3f(1.0,0.0,0.0);
 
 glVertex2f(xa,ya);
 glVertex2f(xb,yb);
 
 glVertex2f(xb,yb);
 glVertex2f(xc,yc);
 
 glVertex2f(xc,yc);
 glVertex2f(xd,yd);
 glFlush();
}

void beizer()
{
 int x,y;
 for(double u=0.0;u<=1.0;u+=0.002)
 {
  x = pow((1-u),3)*xa + 3*u*pow((1-u),2)*xb + 3*pow(u,2)*(1-u)*xc + pow(u,3)*xd;
  y = pow((1-u),3)*ya + 3*u*pow((1-u),2)*yb + 3*pow(u,2)*(1-u)*yc + pow(u,3)*yd;
  plot_point(x,y);
 }
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
glFlush();
}

int count =0;

void mouse(int button, int state, int x, int y)
{
 if(count==0)
 {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
    xa = x; ya =800-y;
    cout<<xa<<" "<<ya<<endl;
    plot_point(xa,ya);
	count++;
   }
 }
 
 else if(count==1)
 {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
    xb = x; yb = 800-y;
    cout<<xb<<" "<<yb<<endl;
    plot_point(xb,yb);
	count++;
   }
 }
 
 else if(count==2)
 {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
    xc = x; yc =800- y;
    cout<<xc<<" "<<yc<<endl;
    plot_point(xc,yc);
	count++;
   }
 }
 
 else if(count==3)
 {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
    xd = x; yd =800- y;
    cout<<xd<<" "<<yd<<endl<<endl;
    plot_point(xd,yd);
	count++;
	hull();
    beizer();
   }
 }
 
 else
 {
  if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   draw();
   count=0;
  }
 }
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 init();
 glutDisplayFunc(draw);
 glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}


