
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include<math.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


struct point {
    int x, y;
    string value = "1111";
};

int x1, x2, x3, x4, y1, y2, y3, y4;
int x1_point, x2_point, y1_point, y2_point, n;

point points[100];

void dda(double x1, double y1, double x2, double y2) {

    float dx, dy, _count, increment_x, increment_y, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dy) > abs(dx))
        _count = abs(dy) * 100;
    else
        _count = abs(dx) * 100;

    increment_x = dx / _count;
    increment_y = dy / _count;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();


    for (double i = 1; i <= _count; i++) {
        x += increment_x;
        y += increment_y;

        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    glFlush();
    glutSwapBuffers();
}

void draw_window() {

    x1 = min(x1_point, x2_point);
    x2 = max(x1_point, x2_point);
    x3 = x2;
    x4 = x1;

    y1 = min(y1_point, y2_point);
    y2 = y1;
    y3 = max(y1_point, y2_point);
    y4 = y3;

    dda(x1, y1, x2, y2);
    dda(x2, y2, x3, y3);
    dda(x3, y3, x4, y4);
    dda(x1, y1, x4, y4);
}

void points_clip() {

    for (int i = 0; i < n; i++) {

        int x, y;
        x = points[i].x;
        y = points[i].y;

        if (y > y3)
            points[i].value[0] = '1';
        else
            points[i].value[0] = '0';

        if (y < y1)
            points[i].value[1] = '1';
        else
            points[i].value[1] = '0';

        if (x > x2)
            points[i].value[2] = '1';
        else
            points[i].value[2] = '0';

        if (x < x1)
            points[i].value[3] = '1';
        else
            points[i].value[3] = '0';
    }

    for (int i = 0; i < n; i++) {

        glBegin(GL_POINTS);

        if (points[i].value == "0000") {
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(points[i].x, points[i].y);
        }
        else {
            glColor3f(0.0, 1.0, 0.0);
            glVertex2f(points[i].x, points[i].y);
        }
        glEnd();
    }
    glFlush();
    glutSwapBuffers();
}

void display() {

    glPointSize(1);
    glColor3f(1.0, 1.0, 0.0);
    dda(-500, 0, 500, 0);
    dda(0, -500, 0, 500);

    glPointSize(1);
    glColor3f(1.0, 1.0, 1.0);
    draw_window();

    glPointSize(3);
    points_clip();
}

int main(int argc, char *argv[])
{
    cout << "The two corner points of the window: " << endl;
    cin >> x1_point >> y1_point >> x2_point>> y2_point;

    cout << "The number of points: ";
    cin >> n;
    cout << "Input vertices: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x;
        cin >> points[i].y;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutCreateWindow("Point Clipping");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
