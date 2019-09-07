o#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int X, Y, r;

void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

void plot_point(int x, int y)
{
 glBegin(GL_POINTS);
 glColor3f(1.0,0.0,0.0);
 glVertex2i(x+X, y+Y);
 glEnd();
}


void myInit (void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glPointSize(1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-800.0, 800.0, -800.0, 800.0);
}


void circle_midpoint()
{
 int x = 0;
 int y = r;
 float d = 5/4 - r;
 plot_point(x, y);
 
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
  plot_point(x, y);
  plot_point(x, -y);
  plot_point(-x, y);
  plot_point(-x, -y);
  plot_point(y, x);
  plot_point(-y, x);
  plot_point(y, -x);
  plot_point(-y, -x);
 }
}

void draw()
{
 text(-795,755,"Akansh Nirmal");
 text(-795,700,"50061342");
 circle_midpoint();
}

void display()
{
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 0.0, 0.0);
 draw();
 glFlush ();
}

int main(int argc, char** argv)
{	
 printf("Enter the X-coordinate = "); 
 scanf("%d",&X);
 printf("\nEnter the Y-coordinate = "); 
 scanf("%d",&Y);
 printf("\nEnter the radius = "); 
 scanf("%d",&r);
 
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (800, 800);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("Circle Midpoint Algorithm");
 glutDisplayFunc(display);
 myInit();
 glutMainLoop();
 return 0;    
}

