#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#define pi 3.142857 

void delay(float n) 
{ 
    float m = 1000 * n; 
    clock_t t = clock(); 
	while (clock() < t + m); 
} 

void myInit (void) 
{   glClearColor(0.0, 0.0, 0.0, 1.0); 
    glColor4f(0.7, 0.5, 1.0,0.5); 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluOrtho2D(-800, 800, -800, 800); 
}

int rad=20;
int j;
float x, y, i; 

void zoomin()
{ 	
	for( j = 0; j < 250; j++){
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON); 
	for (i=0;i<(2*pi);i+=0.001) 
    {   x = rad * cos(i); 
        y = rad * sin(i); 
        glVertex2i(x, y); 
    } 
    rad = rad + 1;
    delay(0.005);
    glEnd(); 
    glFlush();
}
}

void zoomout()
{  
    for( j = 0; j < 250; j++){
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON); 
    for ( i=0;i<(2*pi);i+=0.001) 
    {   x = rad * cos(i); 
        y = rad * sin(i); 
        glVertex2i(x, y); 
    } 
    rad = rad - 1;
    delay(0.005);
    glEnd(); 
    glFlush();
}
}


void display()
{
 for(int k=0;k<10;k++)
 {
 	zoomin();
 	zoomout(); }
}
 	
 	
int main(int argc, char** argv)
{ 	glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800, 800); 
    glutInitWindowPosition(0, 0); 
    glutCreateWindow("Circle Zoom Animation"); 
    myInit(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
  	return 0;
}
