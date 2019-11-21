#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

void text(float x, float y, char *string)
{
 int len, i;
 
 glRasterPos2f(x, y);
 len = strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
}

int levelmax = 15; 
int nleaf = 2; 
float openness = 4.0; 
float factor = 1.5; 
float zoom = 1; 
float windowx =0.5, windowy = 0.9; 
 
void keyboard(unsigned char key, int x, int y)
{
  switch(key) 
  {
    case '-':
      zoom *= 1/1.1;
      glutPostRedisplay();
      break;
    case '+':
      zoom *= 1.1;
      glutPostRedisplay();
      break;
   }
}


void init (void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

int draw_fractal(double x0, double y0, double angle0, int level)
{
  if(level > levelmax) 
   return 0;
   
  float r = 0.15/pow(factor,level-1);
  float angle;
  float x, y, coss, sinn;
  int i;
  for(i = 0; i < nleaf; i++)
  {
    angle = angle0 + i*2*M_PI/nleaf/openness - (nleaf-1)*2*M_PI/nleaf/openness/2;
    coss = cos(angle);
    sinn = sin(angle);
    x = x0 + r*coss;
    y = y0 + r*sinn;
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x, y);
    glEnd();
    draw_fractal(x, y, atan2((y-y0), (x-x0)), level+1);
  }
}

void draw()
{
  float tmp = 0.5/zoom;
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(0.0,1.0,1.0);
  text(-0.9,0.9,"Akansh Nirmal");
  text(-0.9,0.8,"500061342");
  gluOrtho2D(windowx-tmp, windowx+tmp, windowy-tmp, windowy+tmp);
  
  glColor3f(0.5,0.35,0.05);
  glBegin(GL_LINES);
  glVertex2f(0.5,0.5); 
  glVertex2f(0.5,0.6);
  glEnd();
  glColor3f(0.0,0.5,0.0);
  draw_fractal(0.5, 0.6, M_PI/2, 1);
  glFlush();
}

int main (int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(0, 0);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(draw);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
