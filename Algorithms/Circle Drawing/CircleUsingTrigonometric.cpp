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

//for codeblocks users only, not for mac
//#include<bits/stdc++.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include<windows.h>

using namespace std;

double x=0,y,r,p,d,theta=0;

int Round(double x)
{
    return (floor(x+0.5));
}




void draw_axis()
{
    for(int i=-440; i<=480; i++)
    {
        glVertex2d(0,i);
    }
    for(int i=-520; i<=640; i++)
    {
        glVertex2d(i,0);
    }
}
void init()
{
    glClearColor(1.0, 1.0, 1.0,0);
    glColor3f(0.0,0.0,1.0);
    gluOrtho2D(-520,640,-440,480);
    
}

void trigonometric_circle_draw()
{
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POINTS);
    draw_axis();
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,1.0);
    
    x=0;
    
    while(theta<=45)
    {
        
        x=r*cos(theta);
        y=r*sin(theta);
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glVertex2d(y,x);
        glVertex2d(-y,x);
        glVertex2d(-x,y);
        glVertex2d(-x,-y);
        glVertex2d(-y,-x);
        glVertex2d(y,-x);
        glVertex2d(x,-y);
        glEnd();
        glFlush();
        theta=theta+.20;
        
    }
    
    
    
    
    
}
void input()
{
    
    cout<<"Give the Radius"<<endl;
    cin>>r;
    
    
}
int main(int argc,char ** argv)

{
    
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    input();
    glutCreateWindow("Trigonometric Circle Drawing Method");
    init();
    glutDisplayFunc(trigonometric_circle_draw);
    glutMainLoop();
}
