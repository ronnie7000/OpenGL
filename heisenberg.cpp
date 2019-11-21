#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include<math.h>

void text1(int x, int y, char *string)
{
 int len, i;
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
}

void init() 
{ 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Heisenberg");
//glPointSize(3.0);
//glLineWidth(3.0);
 gluOrtho2D(00,800,00,800);
 glColor3f(0.0,0.0,0.0); 
}

struct Color
{
 GLfloat r;
 GLfloat g;
 GLfloat b;	
};

Color bc = {0.0,0.0,0.0};
Color fc2 = {0.01,0.01,0.01};
Color ic = {1.0,1.0,1.0};
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

void plot_point(float x,float y)
{
 glColor3f(0,0,0);
 glBegin(GL_POINTS);
 glVertex2f(x,y);
 glEnd();
 glFlush();
}

int xh1=300,yh1=700;
int xh2=400,yh2=710;
int xh3=500,yh3=700;
int xh4=290,yh4=605;
int xh5=150,yh5=580;
int xh6=400,yh6=575;
int xh7=650,yh7=580;
int xh8=510,yh8=605;

int hat()
{
 int x,y;
 for(double u=0.0;u<=1.0;u+=0.002)
 {
  x = pow((1-u),2)*xh1 + 2*u*(1-u)*xh2 + pow(u,2)*xh3;
  y = pow((1-u),2)*yh1 + 2*u*(1-u)*yh2 + pow(u,2)*yh3;
  plot_point(x,y);
 }
 glBegin(GL_LINES);
 glVertex2i(xh1,yh1);
 glVertex2i(xh4,yh4);
 glVertex2i(xh3,yh3);
 glVertex2i(xh8,yh8);
 glEnd();

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xh4 + 2*u*(1-u)*xh5 + pow(u,2)*xh6;
   y = pow((1-u),2)*yh4 + 2*u*(1-u)*yh5 + pow(u,2)*yh6;
  plot_point(x,y);
 }
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xh8 + 2*u*(1-u)*xh7 + pow(u,2)*xh6;
   y = pow((1-u),2)*yh8 + 2*u*(1-u)*yh7 + pow(u,2)*yh6;
  plot_point(x,y);
 }
glFlush(); 
}

int xs1=280,ys1=550; int xs17=520,ys17=550;
int xs2=283,ys2=510; int xs16=517,ys16=510;
int xs3=285,ys3=490; int xs15=515,ys15=490;
int xs4=300,ys4=488; int xs14=500,ys14=488;
int xs5=360,ys5=488; int xs13=440,ys13=488;
int xs6=375,ys6=490; int xs12=425,ys12=490;
int xs7=378,ys7=510; int xs11=422,ys11=510;
int xs8=380,ys8=522; int xs10=420,ys10=522;
int xs9=400,ys9=530;

void sunglass()
{
 int x,y;
 
 glBegin(GL_LINES);
 glVertex2i(xs1,ys1);
 glVertex2i(xs2,ys2);
 glVertex2i(xs4,ys4);
 glVertex2i(xs5,ys5);
 glVertex2i(xs7,ys7);
 glVertex2i(xs8,ys8);
 glVertex2i(xs17,ys17);
 glVertex2i(xs16,ys16);
 glVertex2i(xs14,ys14);
 glVertex2i(xs13,ys13);
 glVertex2i(xs11,ys11);
 glVertex2i(xs10,ys10);
 glVertex2i(xs1,ys1);
 glVertex2i(xs17,ys17);
 glEnd();
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xs2 + 2*u*(1-u)*xs3 + pow(u,2)*xs4;
   y = pow((1-u),2)*ys2 + 2*u*(1-u)*ys3 + pow(u,2)*ys4;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xs5 + 2*u*(1-u)*xs6 + pow(u,2)*xs7;
   y = pow((1-u),2)*ys5 + 2*u*(1-u)*ys6 + pow(u,2)*ys7;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xs8 + 2*u*(1-u)*xs9 + pow(u,2)*xs10;
   y = pow((1-u),2)*ys8 + 2*u*(1-u)*ys9 + pow(u,2)*ys10;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xs16 + 2*u*(1-u)*xs15 + pow(u,2)*xs14;
   y = pow((1-u),2)*ys16 + 2*u*(1-u)*ys15 + pow(u,2)*ys14;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xs13 + 2*u*(1-u)*xs12 + pow(u,2)*xs11;
   y = pow((1-u),2)*ys13 + 2*u*(1-u)*ys12 + pow(u,2)*ys11;
  plot_point(x,y);
 }
}

int xb1=340,yb1=422; int xb13=460,yb13=422;
int xb2=330,yb2=420; int xb12=470,yb12=420;
int xb3=327,yb3=400; int xb11=473,yb11=400;
int xb4=325,yb4=350; int xb10=475,yb10=350;
int xb5=323,yb5=340; int xb9=477,yb9=340;
int xb6=340,yb6=337; int xb8=460,yb8=337;
int xb7=400,yb7=320;
int xb14=400,yb14=420;

int xb15=347,yb15=392; int xb25=453,yb25=392;
int xb16=338,yb16=367; int xb24=462,yb24=367;
int xb17=340,yb17=360; int xb23=460,yb23=360;
int xb18=360,yb18=350; int xb22=440,yb22=350;
int xb19=380,yb19=360; int xb21=420,yb21=360;
int xb20=395,yb20=375; int xb27=405,yb27=375;
int xb26=400,yb26=390;

void beard()
{
 int x,y;
 
 glBegin(GL_LINES);
 glVertex2i(xb3,yb3);
 glVertex2i(xb4,yb4);
 glVertex2i(xb11,yb11);
 glVertex2i(xb10,yb10);
 glVertex2i(xb20,yb20);
 glVertex2i(xb27,yb27);
 
 
 glEnd();
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb1 + 2*u*(1-u)*xb2 + pow(u,2)*xb3;
   y = pow((1-u),2)*yb1 + 2*u*(1-u)*yb2 + pow(u,2)*yb3;
  plot_point(x,y);
 }
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb4 + 2*u*(1-u)*xb5 + pow(u,2)*xb6;
   y = pow((1-u),2)*yb4 + 2*u*(1-u)*yb5 + pow(u,2)*yb6;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb6 + 2*u*(1-u)*xb7 + pow(u,2)*xb8;
   y = pow((1-u),2)*yb6 + 2*u*(1-u)*yb7 + pow(u,2)*yb8;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb13 + 2*u*(1-u)*xb12 + pow(u,2)*xb11;
   y = pow((1-u),2)*yb13 + 2*u*(1-u)*yb12 + pow(u,2)*yb11;
  plot_point(x,y);
 }
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb10 + 2*u*(1-u)*xb9 + pow(u,2)*xb8;
   y = pow((1-u),2)*yb10 + 2*u*(1-u)*yb9 + pow(u,2)*yb8;
  plot_point(x,y);
 }
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb1 + 2*u*(1-u)*xb14 + pow(u,2)*xb13;
   y = pow((1-u),2)*yb1 + 2*u*(1-u)*yb14 + pow(u,2)*yb13;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb15 + 2*u*(1-u)*xb16 + pow(u,2)*xb17;
   y = pow((1-u),2)*yb15 + 2*u*(1-u)*yb16 + pow(u,2)*yb17;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb17 + 2*u*(1-u)*xb18 + pow(u,2)*xb19;
   y = pow((1-u),2)*yb17 + 2*u*(1-u)*yb18 + pow(u,2)*yb19;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = (1-u)*xb19 + u*xb20;
   y = (1-u)*yb19 + u*yb20;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = (1-u)*xb27 + u*xb21;
   y = (1-u)*yb27 + u*yb21;
  plot_point(x,y);
 }
 
 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb21 + 2*u*(1-u)*xb22 + pow(u,2)*xb23;
   y = pow((1-u),2)*yb21 + 2*u*(1-u)*yb22 + pow(u,2)*yb23;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb23 + 2*u*(1-u)*xb24 + pow(u,2)*xb25;
   y = pow((1-u),2)*yb23 + 2*u*(1-u)*yb24 + pow(u,2)*yb25;
  plot_point(x,y);
 }

 for(double u=0.0;u<=1.0;u+=0.002)
 {
   x = pow((1-u),2)*xb15 + 2*u*(1-u)*xb26 + pow(u,2)*xb25;
   y = pow((1-u),2)*yb15 + 2*u*(1-u)*yb26 + pow(u,2)*yb25;
  plot_point(x,y);
 }
}

void heisenberg(int x, int y)
{
 //H
 glBegin(GL_POLYGON);
 glVertex2i(x,y);
 glVertex2i(x+20,y);
 glVertex2i(x+20,y-50);
 glVertex2i(x,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+20,y-20);
 glVertex2i(x+30,y-20);
 glVertex2i(x+30,y-30);
 glVertex2i(x+20,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+30,y);
 glVertex2i(x+50,y);
 glVertex2i(x+50,y-50);
 glVertex2i(x+30,y-50);
 glEnd();
 
 //E
 glBegin(GL_POLYGON);
 glVertex2i(x+60,y);
 glVertex2i(x+80,y);
 glVertex2i(x+80,y-50);
 glVertex2i(x+60,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+80,y-20);
 glVertex2i(x+90,y-20);
 glVertex2i(x+90,y-30);
 glVertex2i(x+80,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+80,y);
 glVertex2i(x+100,y);
 glVertex2i(x+100,y-10);
 glVertex2i(x+80,y-10);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+80,y-40);
 glVertex2i(x+100,y-40);
 glVertex2i(x+100,y-50);
 glVertex2i(x+80,y-50);
 glEnd();
 
 //I
 glBegin(GL_POLYGON);
 glVertex2i(x+110,y);
 glVertex2i(x+130,y);
 glVertex2i(x+130,y-50);
 glVertex2i(x+110,y-50);
 glEnd();
 
 //S
 glBegin(GL_POLYGON);
 glVertex2i(x+140,y-40);
 glVertex2i(x+180,y-40);
 glVertex2i(x+180,y-50);
 glVertex2i(x+140,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+140,y);
 glVertex2i(x+180,y);
 glVertex2i(x+180,y-10);
 glVertex2i(x+140,y-10);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+140,y-20);
 glVertex2i(x+180,y-20);
 glVertex2i(x+180,y-30);
 glVertex2i(x+140,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+140,y);
 glVertex2i(x+157,y);
 glVertex2i(x+157,y-20);
 glVertex2i(x+140,y-20);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+163,y-30);
 glVertex2i(x+180,y-30);
 glVertex2i(x+180,y-50);
 glVertex2i(x+163,y-50);
 glEnd();
 
 //E
 glBegin(GL_POLYGON);
 glVertex2i(x+190,y);
 glVertex2i(x+210,y);
 glVertex2i(x+210,y-50);
 glVertex2i(x+190,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+210,y-20);
 glVertex2i(x+220,y-20);
 glVertex2i(x+220,y-30);
 glVertex2i(x+210,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+210,y);
 glVertex2i(x+230,y);
 glVertex2i(x+230,y-10);
 glVertex2i(x+210,y-10);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+210,y-40);
 glVertex2i(x+230,y-40);
 glVertex2i(x+230,y-50);
 glVertex2i(x+210,y-50);
 glEnd();
 
 //N
 glBegin(GL_POLYGON);
 glVertex2i(x+240,y);
 glVertex2i(x+260,y);
 glVertex2i(x+260,y-50);
 glVertex2i(x+240,y-50);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+250,y);
 glVertex2i(x+260,y);
 glVertex2i(x+280,y-50);
 glVertex2i(x+270,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+270,y);
 glVertex2i(x+290,y);
 glVertex2i(x+290,y-50);
 glVertex2i(x+270,y-50);
 glEnd();

 //B
 glBegin(GL_POLYGON);
 glVertex2i(x+300,y);
 glVertex2i(x+320,y);
 glVertex2i(x+320,y-50);
 glVertex2i(x+300,y-50);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+320,y);
 glVertex2i(x+340,y);
 glVertex2i(x+340,y-10);
 glVertex2i(x+320,y-10);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+330,y);
 glVertex2i(x+340,y);
 glVertex2i(x+340,y-20);
 glVertex2i(x+330,y-20);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+320,y-20);
 glVertex2i(x+350,y-20);
 glVertex2i(x+350,y-30);
 glVertex2i(x+320,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+340,y-30);
 glVertex2i(x+350,y-30);
 glVertex2i(x+350,y-50);
 glVertex2i(x+340,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+320,y-40);
 glVertex2i(x+350,y-40);
 glVertex2i(x+350,y-50);
 glVertex2i(x+320,y-50);
 glEnd();

 //E
 glBegin(GL_POLYGON);
 glVertex2i(x+360,y);
 glVertex2i(x+380,y);
 glVertex2i(x+380,y-50);
 glVertex2i(x+360,y-50);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+380,y-20);
 glVertex2i(x+390,y-20);
 glVertex2i(x+390,y-30);
 glVertex2i(x+380,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+380,y);
 glVertex2i(x+400,y);
 glVertex2i(x+400,y-10);
 glVertex2i(x+380,y-10);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+380,y-40);
 glVertex2i(x+400,y-40);
 glVertex2i(x+400,y-50);
 glVertex2i(x+380,y-50);
 glEnd();
 
 //R
 glBegin(GL_POLYGON);
 glVertex2i(x+410,y);
 glVertex2i(x+430,y);
 glVertex2i(x+430,y-50);
 glVertex2i(x+410,y-50);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+430,y);
 glVertex2i(x+450,y);
 glVertex2i(x+450,y-10);
 glVertex2i(x+430,y-10);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+440,y);
 glVertex2i(x+450,y);
 glVertex2i(x+450,y-20);
 glVertex2i(x+440,y-20);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+430,y-20);
 glVertex2i(x+460,y-20);
 glVertex2i(x+460,y-30);
 glVertex2i(x+430,y-30);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(x+450,y-20);
 glVertex2i(x+460,y-20);
 glVertex2i(x+460,y-50);
 glVertex2i(x+450,y-50);
 glEnd();
 
 //G
 glBegin(GL_POLYGON);
 glVertex2i(x+470,y);
 glVertex2i(x+490,y);
 glVertex2i(x+490,y-50);
 glVertex2i(x+470,y-50);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+490,y);
 glVertex2i(x+520,y);
 glVertex2i(x+520,y-10);
 glVertex2i(x+490,y-10);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+490,y-40);
 glVertex2i(x+520,y-40);
 glVertex2i(x+520,y-50);
 glVertex2i(x+490,y-50);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+510,y-25);
 glVertex2i(x+520,y-25);
 glVertex2i(x+520,y-50);
 glVertex2i(x+510,y-50);
 glEnd(); 
 glBegin(GL_POLYGON);
 glVertex2i(x+500,y-25);
 glVertex2i(x+510,y-25);
 glVertex2i(x+510,y-35);
 glVertex2i(x+500,y-35);
 glEnd(); 
}

void draw()
{
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2f(0,0);
glVertex2f(800,0);
glVertex2f(800,800);
glVertex2f(0,800);
glEnd();
glColor3f(0.0,0.0,0.0);
text1( 10,775, "Akansh Nirmal");
text1( 10,750, "500061342");
heisenberg(130,100);

hat();
sunglass();
beard();

glFlush();
}

void mouse (int button, int state, int x, int y)
{
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 { flood(x,800-y); }
 
 else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
 { glClear(GL_COLOR_BUFFER_BIT);
   draw(); }
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


