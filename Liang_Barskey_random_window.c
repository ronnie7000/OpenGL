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
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 glFlush();
}

void Draw()
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

text( 10,775, "Akansh Nirmal");
text( 10,750, "500061342");
text( 410,750," Y-Axis");
text( 700,410," X-Axis");
glEnd();
glFlush();
}

int xi,xf,yi,yf;

void pre_bresenham(int x1, int y1, int x2, int y2)
{
 if(x1<x2)
 { 
  xi = x1;
  xf = x2;
  yi = y1;
  yf = y2;
  
  Bresenham_algo(x1,y1,x2,y2); 
 }
 else
 {
  xi = x2;
  xf = x1;
  yi = y2;
  yf = y1;
   
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


int xmin=0,xmax=0,ymin=0,ymax=0;
double p[0],q[0];
int xt1, yt1, xt2, yt2;

void clipping_window()
{
 int rx = (rand()%300)+200;
 int ry = (rand()%300)+200;

 xmin = rx;
 xmax = rx+200;
 ymin = ry;
 ymax = ry+200;
 
 glColor3f(1.0,0.0,1.0);
 glBegin(GL_LINES);
 
 glVertex2f(xmin,ymin);
 glVertex2f(xmax,ymin); 
 glVertex2f(xmax,ymin);
 glVertex2f(xmax,ymax);
 glVertex2f(xmax,ymax);
 glVertex2f(xmin,ymax);
 glVertex2f(xmin,ymax);
 glVertex2f(xmin,ymin);
 glEnd();

int x = liang_barsky(xi,yi,xf,yf);
 glFlush();
}

int liang_barsky(int x1,int y1,int x2,int y2)
{
 float t1=0.0,t2=1.0;
 int dx=x2-x1;
 int dy=y2-y1;
 int i;
 float t;
 p[0]=-dx;
 q[0]=x1-xmin;
 p[1]=dx;
 q[1]=xmax-x1;
 p[2]=-dy;
 q[2]=y1-ymin;
 p[3]=dy;
 q[3]=ymax-y1;
 
 for(i=0;i<4;i++)
 {
  if(p[i]==0 && q[i]<0)
  { 
   glColor3f(0.0,1.0,0.0);
   pre_bresenham(x1,y1,x2,y2);
   return 0;
  }
  
  if(p[i]<0.0)
  {
   t=q[i]/p[i];
   if(t>t1)
   {
    t1=t;
   }
  }
  if(p[i]>0.0)
  {  
   t=q[i]/p[i];
   if(t<t2)
   { 
    t2=t;
   }
  }
 }
 
 if(t1<t2)
 {  
  xt1=x1+t1*(x2-x1);
  yt1=y1+t1*(y2-y1);
  xt2=x1+t2*(x2-x1);
  yt2=y1+t2*(y2-y1);
     	 
  glColor3f(0.0,0.0,1.0);
  pre_bresenham( xt1, yt1, xt2, yt2);
  glColor3f(1.0,1.0,0.0);
  pre_bresenham( x1, y1, xt1, yt1);
  glColor3f(1.0,1.0,0.0);
  pre_bresenham( xt2, yt2, x2, y2);
  return 1;
 }
 
 else
 {
  glColor3f(0.0,1.0,0.0);
  pre_bresenham(x1,y1,x2,y2);
  return 0;
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
 { 
 glColor3f(0.0,1.0,0.0);
 pre_bresenham(coordinate[0].x, coordinate[0].y, coordinate[1].x, coordinate[1].y);
 count=0;
 }
}

void Key(unsigned char key,int x,int y)
{
 if(key==32)
 {
  glClear(GL_COLOR_BUFFER_BIT);
  Draw();
  clipping_window();
 }
}


int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(800,800);
 glutCreateWindow("Liang Barsky Algorithm");
 glutDisplayFunc(Draw);
 glutKeyboardFunc(Key);
 glutMouseFunc(Mouse);
 myInit();
 glutMainLoop();
 return 0;
}

