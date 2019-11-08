#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void init() 
{ 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Filling Algorithm");
 gluOrtho2D(0,800,0,800); 
}

void background()
{
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(0,800);
 glVertex2f(800,800);
 glVertex2f(800,0);
 glEnd();
 glFlush(); 
}

void polygon()
{
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(350,350);
 glVertex2f(350,450);
 glVertex2f(450,450);
 glVertex2f(450,350);
 glEnd();
 glFlush();	
}

struct Color
{
 GLfloat r;
 GLfloat g;
 GLfloat b;	
};

Color bc = {1.0,1.0,0.0};
Color fc1 = {0.0,0.0,1.0};
Color fc2 = {1.0,0.0,0.0};
Color ic = {0.0,0.0,0.0};
Color col;

void getPixelColor(int x, int y)
{
 glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &col);	
}

void setPixelColor(int x, int y, Color fc)
{
 glColor3f(fc.r, fc.g, fc.b);
 glBegin(GL_POINTS);
 glVertex2f(x, y);
 glEnd();
 glFlush();
}

int flood(int x, int y) 
{
 getPixelColor(x, y);

 if(col.r == ic.r && col.g == ic.g && col.b == ic.b)
 {
  setPixelColor(x,y,fc2);
  flood(x+1,y);
  flood(x,y+1);
  flood(x-1,y);
  flood(x,y-1);
 }
 return 0;
}

int boundary(int x, int y) 
{
 getPixelColor(x,y);
    
 if((col.r!=bc.r || col.g!=bc.g || col.b!=bc.b) && (col.r!=fc1.r || col.g!=fc1.g || col.b!=fc1.b))
 {
  setPixelColor(x,y,fc1);
  boundary(x+1,y);
  boundary(x,y+1);
  boundary(x-1,y);
  boundary(x,y-1);
 }
 return 0;
}

void mouse (int button, int state, int x, int y)
{
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 { text(300,550," Flood Fill Algorithm.");
   flood(x,800-y); }
 else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
 { text(280,550," Boundary Fill Algorithm."); 
   boundary(x,800-y); }
}

void dis()
{ 
 background();
 polygon();
 glColor3f(0.0,1.0,1.0);
 text(10,750,"Akansh Nirmal");
 text(10,730,"50061342");
}

int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(dis);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
