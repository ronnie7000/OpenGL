#include<stdio.h>
#include<GL/glut.h>
#define pi 3.142857 
#include <math.h>

float i;
int x,y;

void circle(int x1, int y1, int rad)
{
 glBegin(GL_POLYGON);
 for(i=0;i<=(2*pi);i=i+0.001)
 {
  x = x1+(rad*cos(i));
  y = y1+(rad*sin(i));
  glVertex2f(x,y);
 }
 glEnd();
}

void day()
{
 glClear(GL_COLOR_BUFFER_BIT);
 
 glColor3f(0.6,1.0,1.0); //Sky
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(1980,0);
 glVertex2f(1980,1080);
 glVertex2f(0,1080);
 glEnd();
 
 glColor3f(0.5,0.7,0.0); //Land
 glBegin(GL_POLYGON);
 glVertex2f(0,500);
 glVertex2f(1980,500);
 glVertex2f(1980,300);
 glVertex2f(0,100);
 glEnd();
 
 glColor3f(0.0,0.35,0.5); //River
 glBegin(GL_POLYGON);
 glVertex2f(0,100);
 glVertex2f(1980,300);
 glVertex2f(1980,0);
 glVertex2f(0,0);
 glEnd();
 
 glColor3f(0.5,0.5,0.05); //mountains
 glBegin(GL_TRIANGLES);
 glVertex2f(0,500);
 glVertex2f(200,750);
 glVertex2f(400,500);
 glEnd();
 
 glColor3f(0.5,0.5,0.05); //mountains
 glBegin(GL_TRIANGLES);
 glVertex2f(380,500);
 glVertex2f(580,750);
 glVertex2f(780,500);
 glEnd();
 
 
 glColor3f(0.5,0.5,0.05); //mountains
 glBegin(GL_TRIANGLES);
 glVertex2f(760,500);
 glVertex2f(960,750);
 glVertex2f(1160,500);
 glEnd();
 
 
 glColor3f(0.5,0.5,0.05); //mountains
 glBegin(GL_TRIANGLES);
 glVertex2f(1140,500);
 glVertex2f(1340,750);
 glVertex2f(1540,500);
 glEnd();
 
 glColor3f(0.5,0.5,0.05); //mountains
 glBegin(GL_TRIANGLES);
 glVertex2f(1520,500);
 glVertex2f(1720,750);
 glVertex2f(1980,500);
 glEnd();
 
 
 glColor3f(0.5,0.35,0.05); //hut bottom
 glBegin(GL_POLYGON);
 glVertex2f(50,200);
 glVertex2f(500,200);
 glVertex2f(500,350);
 glVertex2f(50,350);
 glEnd();
 
 glColor3f(0.5,0.35,0.05); //hut top
 glBegin(GL_TRIANGLES);
 glVertex2f(30,350);
 glVertex2f(270,450);
 glVertex2f(530,350);
 glEnd();
 
 glColor3f(0.5,0.35,0.05); //hut chimney
 glBegin(GL_POLYGON);
 glVertex2f(350,400);
 glVertex2f(380,400);
 glVertex2f(380,480);
 glVertex2f(350,480);
 glEnd();
 
 glColor3f(0.8,0.8,0.0); //hut gate
 glBegin(GL_POLYGON);
 glVertex2f(150,200);
 glVertex2f(250,200);
 glVertex2f(250,300);
 glVertex2f(150,300);
 glEnd();
 
 glColor3f(0.8,0.8,0.0); //hut window
 glBegin(GL_POLYGON);
 glVertex2f(350,250);
 glVertex2f(400,250);
 glVertex2f(400,300);
 glVertex2f(350,300);
 glEnd();
 
 glColor3f(0.5,0.35,0.05); //boat left
 glBegin(GL_TRIANGLES);
 glVertex2f(1350,150);
 glVertex2f(1450,150);
 glVertex2f(1450,70);
 glEnd();
 
 glColor3f(0.5,0.35,0.05); //boat middle
 glBegin(GL_POLYGON);
 glVertex2f(1450,70);
 glVertex2f(1650,70);
 glVertex2f(1650,150);
 glVertex2f(1450,150);
 glEnd();
 
 glColor3f(0.5,0.35,0.05); //boat right
 glBegin(GL_TRIANGLES);
 glVertex2f(1650,150);
 glVertex2f(1650,70);
 glVertex2f(1750,150);
 glEnd();
 
 glColor3f(0.5,0.5,0.1); //pole
 glBegin(GL_POLYGON);
 glVertex2f(1250,300);
 glVertex2f(1265,300);
 glVertex2f(1265,250);
 glVertex2f(1250,250);
 glEnd();
 
 glColor3f(0.7,0.7,0.7); //rope
 glBegin(GL_LINES);
 glVertex2f(1250,285);
 glVertex2f(1265,285);
 glVertex2f(1265,287);
 glVertex2f(1250,287);
 glVertex2f(1260,287);
 glVertex2f(1370,150);
 glEnd();
 
 glColor3f(0.3,0.09,0.01); //trunk
 glBegin(GL_POLYGON);
 glVertex2f(1550,400);
 glVertex2f(1600,400);
 glVertex2f(1600,300);
 glVertex2f(1550,300);
 glEnd();
 
 glColor3f(0.1,0.5,0.1); //leaves
 circle(1575,450,90);
 circle(1525,450,90);
 circle(1625,450,90);
 circle(1550,490,90);
 circle(1600,490,90);
 circle(1575,510,90); 
 
 glColor3f(1.0,0.7,0.0); //sun
 circle(1200,900,90);
 
 glColor3f(1.0,1.0,1.0); //clouds
 circle(200,850,35);
 circle(250,850,35);
 circle(300,850,35);
 circle(350,850,35);
 circle(225,900,35);
 circle(275,900,35);
 circle(325,900,35);
 circle(600,950,35);
 circle(650,950,35);
 circle(700,950,35);
 circle(750,950,35);
 circle(625,1000,35);
 circle(675,1000,35);
 circle(725,1000,35);
 circle(1000,850,35);
 circle(1050,850,35);
 circle(1100,850,35);
 circle(1150,850,35);
 circle(1025,900,35);
 circle(1075,900,35);
 circle(1125,900,35);
 circle(1500,950,35);
 circle(1550,950,35);
 circle(1600,950,35);
 circle(1650,950,35);
 circle(1525,1000,35);
 circle(1575,1000,35);
 circle(1625,1000,35);

 glFlush();
}


void myInit()
{
 glPointSize(1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, 1980.0, 0.0, 1080.0);
}

void display()
{
 day();
}

void night()
{
 glClear(GL_COLOR_BUFFER_BIT);
 
  glColor3f(0.0,0.0,0.4); //Sky
  glBegin(GL_POLYGON);
  glVertex2f(0,0);
  glVertex2f(1980,0);
  glVertex2f(1980,1080);
  glVertex2f(0,1080);
  glEnd();
  
  glColor3f(0.5,0.7,0.0); //Land
  glBegin(GL_POLYGON);
  glVertex2f(0,500);
  glVertex2f(1980,500);
  glVertex2f(1980,300);
  glVertex2f(0,100);
  glEnd();
  
  glColor3f(0.0,0.35,0.5); //River
  glBegin(GL_POLYGON);
  glVertex2f(0,100);
  glVertex2f(1980,300);
  glVertex2f(1980,0);
  glVertex2f(0,0);
  glEnd();
  
  glColor3f(0.5,0.5,0.05); //mountains
  glBegin(GL_TRIANGLES);
  glVertex2f(0,500);
  glVertex2f(200,750);
  glVertex2f(400,500);
  glEnd();
  
  glColor3f(0.5,0.5,0.05); //mountains
  glBegin(GL_TRIANGLES);
  glVertex2f(380,500);
  glVertex2f(580,750);
  glVertex2f(780,500);
  glEnd();
  
  
  glColor3f(0.5,0.5,0.05); //mountains
  glBegin(GL_TRIANGLES);
  glVertex2f(760,500);
  glVertex2f(960,750);
  glVertex2f(1160,500);
  glEnd();
  
  
  glColor3f(0.5,0.5,0.05); //mountains
  glBegin(GL_TRIANGLES);
  glVertex2f(1140,500);
  glVertex2f(1340,750);
  glVertex2f(1540,500);
  glEnd();
  
  glColor3f(0.5,0.5,0.05); //mountains
  glBegin(GL_TRIANGLES);
  glVertex2f(1520,500);
  glVertex2f(1720,750);
  glVertex2f(1980,500);
  glEnd();
 
 
  glColor3f(0.5,0.35,0.05); //hut bottom
  glBegin(GL_POLYGON);
  glVertex2f(50,200);
  glVertex2f(500,200);
  glVertex2f(500,350);
  glVertex2f(50,350);
  glEnd();
  
  glColor3f(0.5,0.35,0.05); //hut top
  glBegin(GL_TRIANGLES);
  glVertex2f(30,350);
  glVertex2f(270,450);
  glVertex2f(530,350);
  glEnd();
  
  glColor3f(0.5,0.35,0.05); //hut chimney
  glBegin(GL_POLYGON);
  glVertex2f(350,400);
  glVertex2f(380,400);
  glVertex2f(380,480);
  glVertex2f(350,480);
  glEnd();
  
  glColor3f(0.8,0.8,0.0); //hut gate
  glBegin(GL_POLYGON);
  glVertex2f(150,200);
  glVertex2f(250,200);
  glVertex2f(250,300);
  glVertex2f(150,300);
  glEnd();
  
  glColor3f(0.8,0.8,0.0); //hut window
  glBegin(GL_POLYGON);
  glVertex2f(350,250);
  glVertex2f(400,250);
  glVertex2f(400,300);
  glVertex2f(350,300);
  glEnd();
  
  glColor3f(0.5,0.35,0.05); //boat left
  glBegin(GL_TRIANGLES);
  glVertex2f(1350,150);
  glVertex2f(1450,150);
  glVertex2f(1450,70);
  glEnd();
  
  glColor3f(0.5,0.35,0.05); //boat middle
  glBegin(GL_POLYGON);
  glVertex2f(1450,70);
  glVertex2f(1650,70);
  glVertex2f(1650,150);
  glVertex2f(1450,150);
  glEnd();
  
  glColor3f(0.5,0.35,0.05); //boat right
  glBegin(GL_TRIANGLES);
  glVertex2f(1650,150);
  glVertex2f(1650,70);
  glVertex2f(1750,150);
  glEnd();
  
  glColor3f(0.5,0.5,0.1); //pole
  glBegin(GL_POLYGON);
  glVertex2f(1250,300);
  glVertex2f(1265,300);
  glVertex2f(1265,250);
  glVertex2f(1250,250);
  glEnd();
  
  glColor3f(0.7,0.7,0.7); //rope
  glBegin(GL_LINES);
  glVertex2f(1250,285);
  glVertex2f(1265,285);
  glVertex2f(1265,287);
  glVertex2f(1250,287);
  glVertex2f(1260,287); 
  glVertex2f(1370,150);
  glEnd();
  
  glColor3f(0.3,0.09,0.01); //trunk
  glBegin(GL_POLYGON);
  glVertex2f(1550,400);
  glVertex2f(1600,400);
  glVertex2f(1600,300);
  glVertex2f(1550,300);
  glEnd();
   
  glColor3f(0.1,0.5,0.1); //leaves
  circle(1575,450,90); 
  circle(1525,450,90);
  circle(1625,450,90);
  circle(1550,490,90);
  circle(1600,490,90);
  circle(1575,510,90); 
  
  glColor3f(0.8,0.8,0.0); //moon
  circle(1200,900,90);
  
  glColor3f(0.7,0.7,0s.7); //clouds
  circle(200,850,35);
  circle(250,850,35);
  circle(300,850,35);
  circle(350,850,35);
  circle(225,900,35);
  circle(275,900,35);
  circle(325,900,35);
  circle(600,950,35);
  circle(650,950,35);
  circle(700,950,35);
  circle(750,950,35);
  circle(625,1000,35);
  circle(675,1000,35);
  circle(725,1000,35);
  circle(1000,850,35);
  circle(1050,850,35);
  circle(1100,850,35);
  circle(1150,850,35);
  circle(1025,900,35);
  circle(1075,900,35);
  circle(1125,900,35);
  circle(1500,950,35);
  circle(1550,950,35);
  circle(1600,950,35); 
  circle(1650,950,35);
  circle(1525,1000,35);
  circle(1575,1000,35);
  circle(1625,1000,35);

  glFlush();
}


void change(char key, int mousex, int mousey)
{
 if(key == 27)
  {
   night(); 
  }
 else if(key == 32)
 {
  day();
 }
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(1980,1080);
 glutCreateWindow("Hut");
 glutDisplayFunc(display);
 glutKeyboardFunc(change);
 myInit();
 glutMainLoop();
 return 0;	
}
