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

int _x1, _x2, _x3, _x4, _y1, _y2, _y3, _y4, mid_x, mid_y;

bool visited[10000][10000];
int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

void flood_fill(int x, int y){
    visited[x + 100][y + 100] = true;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for(int i = 0; i <= 3; i++){
        int vx = x + xx[i];
        int vy = y + yy[i];
        if(vx > _x1 && vx < _x2 && vy > _y1 && vy < _y2 && !visited[vx + 100][vy + 100])
            flood_fill(vx, vy);
    }
}

void bresenham_algo(int x1, int y1, int x2, int y2){
    int dx, dy, x, y, di;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    glEnd();
    glFlush();

    if(dx > dy){ 
        x = x1;
        y = y1;
        di = (2 * dy) - dx;

        for(int i = 0; i < dx; i++){
            if(di >= 0){
                di = di + 2 * (dy - dx);

                if(y1 > y2)
                    y--;
                else
                    y++;
            }
            else
                di = di + (2 * dy);
            x++;

            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();
        }
        glFlush();
        glutSwapBuffers();
    }
    else{ 
        x = x1;
        y = y1;
        di = (2 * dx) - dy;

        for(int i = 0; i < dy; i++){
            if(y1 > y2)
                y--;
            else
                y++;

            if(di >= 0){
                x++;
                di = di + 2 * (dx - dy);
            }
            else
                di = di + (2 * dx);

            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();

        }
        glFlush();
        glutSwapBuffers();
    }
}

void display(){
    glPointSize(1.0);
    glColor3f(1.0,1.0,0.0);

    bresenham_algo(-500, 0, 500, 0);
    bresenham_algo(0, -500, 0, 500);

    glColor3f(1.0,1.0,1.0);

    bresenham_algo(_x1, _y1, _x3, _y3);
    bresenham_algo(_x1, _y1, _x4, _y4);
    bresenham_algo(_x3, _y3, _x2, _y2);
    bresenham_algo(_x4, _y4, _x2, _y2);

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(mid_x, mid_y);
    glEnd();
    glFlush();

    flood_fill(mid_x, mid_y);
    glFlush();
}

int main(int argc, char** argv){
    cout<<"Enter coordinates of two corner points of a rectangle. Please note that maximum Length of a side can be 250."<<endl;
    cout << "First point(between 0 and 500):" << endl;
    cin >> _x1 >> _y1;

    cout << "Second point(between 0 and 500):" << endl;
    cin >> _x2 >> _y2;

    if(_x1 > _x2)
        swap(_x1, _x2);
    if(_y1 > _y2)
        swap(_y1, _y2);

    _x3 = _x2, _x4 = _x1;
    _y3 = _y1, _y4 = _y2;

    mid_x = (_x1 + _x2) / 2;
    mid_y = (_y1 + _y2) / 2;

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(450,100);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutCreateWindow("Drawing a rectangle and color with FloodFill algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 500, -100, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}