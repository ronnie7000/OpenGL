#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<time.h>

using namespace std;

void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void delay(float n) 
{ 
    float m = 1000 * n; 
    clock_t t = clock(); 
	while (clock() < t + m); 
} 

void init() 
{ 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Square Fractal");
 gluOrtho2D(0,800,0,800);
 glColor3f(0.0,1.0,1.0); 
}

int length = 200;
int centerx = 400;
int centery = 400;

float r = 0.5;
float g = 0;
float b = 0.9;

void square(int cx, int cy, int len)
{
 glColor3f(r,g,b);
 glBegin(GL_POLYGON);
 glVertex2f(cx-len,cy-len); 
 glVertex2f(cx+len,cy-len);
 glVertex2f(cx+len,cy+len);
 glVertex2f(cx-len,cy+len);
 glEnd();  
}

void pattern(int count, int cenx, int ceny, int len)
{
 if(count>0)
 {
  square(cenx,ceny,len);
  
  int cx1 = cenx-len;
  int cy1 = ceny-len;
  int cx2 = cenx+len;
  int cy2 = ceny-len;
  int cx3 = cenx+len;
  int cy3 = ceny+len;
  int cx4 = cenx-len;
  int cy4 = ceny+len;
  int l = len/2;
  
  pattern(count-1,cx1,cy1,l);
  pattern(count-1,cx2,cy2,l);
  pattern(count-1,cx3,cy3,l);
  pattern(count-1,cx4,cy4,l);
 }
}

void draw()
{
glClear(GL_COLOR_BUFFER_BIT);
text(-790,775, "Akansh Nirmal");
text(-790,750, "500061342");
pattern(9,centerx,centery,length);
glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 init();
 glutDisplayFunc(draw);
 glutMainLoop();
 return 0;
}
