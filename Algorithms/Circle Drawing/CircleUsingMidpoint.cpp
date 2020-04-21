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

using namespace std;

double x=0,y,r,p,d,cx,cy;

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

void midpoint_draw()
{
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POINTS);
    draw_axis();
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,1.0);
    
    x=0;
    y=r;
    d=3-2*r;
    while(x<=y)
    {
        glBegin(GL_POINTS);
        glVertex2d(cx+x,cy+y);
        glVertex2d(cx+y,cy+x);
        glVertex2d(cx-y,cy+x);
        glVertex2d(cx-x,cy+y);
        glVertex2d(cx-x,cy-y);
        glVertex2d(cx-y,cy-x);
        glVertex2d(cx+y,cy-x);
        glVertex2d(cx+x,cy-y);
        glEnd();
        glFlush();
        if(d<0)
        {
            d=d+2*x+3;
            
        }
        else
        {
            d=d+2*(x-y)+5;
            y--;
        }
        x++;
    }
    
    
    
    
    
}
void input()
{
    
    cout<<"Give the Radius"<<endl;
    cin>>r;
    cout<<"Co-ordinate of Center X Y "<<endl;
    
    cin>>cx>>cy;
    
}
int main(int argc,char ** argv)

{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    input();
    glutCreateWindow("Mid Point Algorithm");
    init();
    glutDisplayFunc(midpoint_draw);
    glutMainLoop();
}
