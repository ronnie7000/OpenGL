#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

int rad = 20;

void circle (int x, int y)
{ 	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON); 
    float xi, yi, i; 
	for (i=0;i<(2*pi);i+=0.001) 
    {   xi = x+(rad * cos(i)); 
        yi = y+(rad * sin(i)); 
        glVertex2i(xi, yi); 
    } 
   glEnd();
   glFlush();
}

void point(int button, int state, int x, int y)
{
 if((button==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))
   circle(x,800-y);
   //glutPostRedisplay();
}

void keys(char key)
{
 if(key == 32)
 glutDestroyWindow(glutGetWindow());
}

void display()
{
  glClearColor(0.0, 0.0, 0.0, 1.0); 
    glColor4f(0.5, 0.5, 1.0,0.5); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluOrtho2D(0,800,0,800); 
}

int main(int argc, char** argv)
{ 	glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800, 800); 
    glutInitWindowPosition(0, 0); 
    glutCreateWindow("Lab 1"); 
    
	glutDisplayFunc(display);  
    glutMouseFunc(point); 
    glutKeyboardFunc(keys);
	glutMainLoop(); 
  	return 0;
}
