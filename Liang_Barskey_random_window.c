#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void text(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
}

int first = 0;  
int xi=0, yi=0, xf=0, yf=0; 

int xmin,ymin,xmax,ymax;
double p[4],q[4];
int xt1;
int yt1;
int xt2;
int yt2;

void delay(int number_of_seconds) 
{ 
 int milli_seconds = 1000 * number_of_seconds; 
 clock_t start_time = clock(); 
 while (clock() < start_time + milli_seconds); 
} 

void plot_point(GLint x, GLint y) 
{
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
}

void Bresenham(int x1, int y1, int x2, int y2)
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
  
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
  Draw();
  glColor3f(1.0,0.0,1.0);
  Bresenham( xmin, ymin, xmax, ymin);
  Bresenham( xmax, ymin, xmax, ymax);
  Bresenham( xmin, ymax,xmax, ymax);
  Bresenham( xmin, ymax, xmin, ymin);
  
  glColor3f(0.0,0.0,1.0);
  Bresenham( xt1, yt1, xt2, yt2);
  glColor3f(0.0,1.0,0.0);
  Bresenham( xi, yi, xt1, yt1);
  glColor3f(0.0,1.0,0.0);
  Bresenham( xt2, yt2, xf, yf);
  return 1;
 }
 
 else
 {
  Draw();
  glColor3f(0,1,0);
  glFlush();
  Bresenham(xi,yi,xf,yf);
  
  glColor3f(1.0,0.0,1.0);
  Bresenham( xmin, ymin, xmax, ymin);
  Bresenham( xmax, ymin, xmax, ymax);
  Bresenham( xmin, ymax,xmax, ymax);
  Bresenham( xmin, ymax, xmin, ymin);
  return 0; 
 
 }
}

void clipping_window()
{
 int flag=0;
 while(flag==0)
 {
  int randomX=(rand()%300)+150;
  int randomY=(rand()%300)+150;
  if(randomX<599&&randomX>149)
  {
   if(randomY<599&&randomY>149)
   {
    glClear(GL_COLOR_BUFFER_BIT);
    
	glColor3f(0.0,1.0,0.0);
	Bresenham( xi, yi, xf, yf);
    
	xmin=randomX;
    xmax=randomX+200;
    ymin=randomY;
    ymax=randomY+200;
    
    glColor3f(1.0,0.0,1.0);
	Bresenham( xmin, ymin, xmax, ymin);
    Bresenham( xmax, ymin, xmax, ymax);
    Bresenham( xmin, ymax,xmax, ymax);
    Bresenham( xmin, ymax, xmin, ymin);
    
	int x = liang_barsky(xi,yi,xf,yf);
    delay(2);
   }
  }
 }
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

void Mouse(int button, int state, int x, int y) 
{
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
 { 
  switch(first)  
  {  
   case 0:  
   xi = x;  
   yi = 800-y;  
   first = 1;  
   break;  
   
   case 1:  
   xf = x;  
   yf = 800-y;

   if(xi>xf)
   {
    int temp=xi;
    xi=xf;
    xf=temp;  
    temp=yi;
    yi=yf;
    yf=temp;  
   } 
   glColor3f(0.0,1.0,0.0);
   Bresenham( xi, yi, xf, yf);
   first = 2;
   break;
  }  
 }  
}  

void Keyboard(unsigned char key,int x,int y)
{
 glClear(GL_COLOR_BUFFER_BIT);
 if(key==32)
 {
  clipping_window();
 }
}

void init() 
{ 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Liang Barsky Algorithm");
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(0,800,0,800); 
}
int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(Draw);
  glutMouseFunc(Mouse); 
  glutKeyboardFunc(Keyboard); 
  glutMainLoop();
  return 0;
}
