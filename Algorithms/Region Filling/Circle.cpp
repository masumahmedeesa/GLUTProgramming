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

int center_x, center_y, radius, radius_square;

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
        int check_radius_square = (abs(vx) - center_x) * (abs(vx) - center_x) + (abs(vy) - center_y) * (abs(vy) - center_y);
        if (check_radius_square < radius_square && !visited[vx + 100][vy + 100])
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

void bresenham()
{
    int x = 0, y = radius, d = 3 - (2 * radius);

    glBegin(GL_POINTS);

    while(x <= y){
        glVertex2i(center_x + x, center_y + y);
        glVertex2i(center_x + x, center_y - y);
        glVertex2i(center_x - x, center_y + y);
        glVertex2i(center_x - x, center_y - y);
        glVertex2i(center_x + y, center_y + x);
        glVertex2i(center_x + y, center_y - x);
        glVertex2i(center_x - y, center_y + x);
        glVertex2i(center_x - y, center_y - x);

        if(d < 0)
            d = d + (4 * x) + 6;
        else{
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

void display()
{
    glPointSize(1.0);
    glColor3f(1.0,1.0,0.0);

    bresenham_algo(-500, 0, 500, 0);
    bresenham_algo(0, -500, 0, 500);

    glColor3f(1.0,1.0,1.0);
    bresenham();

    glColor3f(1.0,0.0,0.0);
    flood_fill(center_x, center_y);

    glFlush();
}

int main(int argc, char *argv[]) {
    cout<<"Enter the coordinates of center (between 100 and 450) and radius (max 100) of the circle"<<endl;
    cout << "Center: " << endl;
    cin >> center_x >> center_y;

    cout << "Radius:" << endl;
    cin >> radius;

    radius_square = radius * radius;

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(450,100);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutCreateWindow("Drawing a circle and color with FloodFill algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 500, -100, 500);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}