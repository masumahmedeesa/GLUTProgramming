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


float firstX,secondX,firstY,secondY;

void display(void)
{
    float dy,dx,step,x,y,k,Xin,Yin;
    dx=secondX-firstX;
    dy=secondY-firstY;
    
    if(abs(dx)> abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);
    
    Xin = dx/step;
    Yin = dy/step;
    
    x= firstX;
    y=firstY;
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    
    for (k=1 ; k<=step; k++)
    {
        x= x + Xin;
        y= y + Yin;
        
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    glFlush();
}

void init(void)
{
    //glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
    printf( "Enter (firstX, firstY, secondX, secondY)\n");
    scanf("%f %f %f %f", &firstX, &firstY, &secondX, &secondY);
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1500, 1500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
