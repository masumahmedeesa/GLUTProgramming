#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <iostream>

int x1,yy,x2,y2;
void display();
void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
void drawPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void rawLine(int x1,int y1,int x2,int y2)
{
    int b,m;
    int dx, dy,x,y;
    
    
    dx = x2-x1;
    dy = y2-y1;
    x=x1; y=y1;
    m = dy/dx;
    b=y1-(m*x1);
    
    if (dx > dy) {
        for (y=y1; y<=y2; y++) {
            drawPoint(x, y);
            x=(y-b)/m;
            
        }
        
    }
    else {
        
        for (x=x1;x<=x2;x++) {
            drawPoint(x, y);
            y=(m*x)+b;
            
        }
    }
    
}
void display()
{
    
    rawLine(x1,yy,x2,y2);
    glFlush();
}


int main(int argc,char **argv)
{
    printf( "Enter x1, y1, x2, y2 : ");
    scanf("%d %d %d %d", &x1, &yy, &x2, &y2);
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Direct Method");
    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
    
}