
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
using namespace std;


struct point {
    int x, y;
    string value = "1111";
};
point points[100];

int n, m;
vector < pair<int,int> > vertices;

void dda(double x1, double y1, double x2, double y2) {

    double dx, dy, _count, increment_x, increment_y, x, y;

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

void draw_polygon() {

    int x1, y1, x2, y2;

    for (int i = 0; i < n; i++) {
        x1 = vertices[i].first;
        y1 = vertices[i].second;

        if (i == n-1) {
            x2 = vertices[0].first;
            y2 = vertices[0].second;
        }
        else {
            x2 = vertices[i + 1].first;
            y2 = vertices[i + 1].second;
        }

        if (x1 > x2) {
            swap(x1,x2);
            swap(y1,y2);
        }

        dda(x1, y1, x2, y2);
    }
}

void clip_points() {

    for (int i = 0; i < m; i++) {

        int x = points[i].x;
        int y = points[i].y;
        int check = 0;

        for (int j = 0; j < n; j++) {

            int x1, y1, x2, y2;

            if (j == n - 1) {
                x1 = vertices[j].first;
                y1 = vertices[j].second;

                x2 = vertices[0].first;
                y2 = vertices[0].second;
            }
            else {
                x1 = vertices[j].first;
                y1 = vertices[j].second;

                x2 = vertices[j + 1].first;
                y2 = vertices[j + 1].second;
            }

            check = ((x2 - x1) * (y - y1)) - ((y2 - y1) * (x - x1));

            if (check < 0) {

                glPointSize(2);
                glColor3f(1.0, 0.0, 0.0);
                glBegin(GL_POINTS);
                glVertex2f(x, y);
                glEnd();
                break;
            }
        }
        if (check >= 0) {

            glPointSize(2);
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();
        }
    }

    glFlush();
    glutSwapBuffers();
}

void display() {

    glPointSize(1);
    glColor3f(1.0, 1.0, 0.0);
    dda(-500, 0, 500, 0);
    dda(0, -500, 0, 500);

    glColor3f(1.0,1.0,1.0);
    draw_polygon();

    glColor3f(1.0,1.0,1.0);
    clip_points();
}

int main(int argc, char* argv[]) {

    cout << "Input number of edges: " << endl;
    cin >> n;

    int x, y;
    cout << "Input vertices anticlockwise: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }

    cout << "Input number of points:" << endl;
    cin >> m;
    cout << "Input points:" << endl;

    for (int i = 0; i < m; i++)
        cin >> points[i].x >> points[i].y;

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(150, 150);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutCreateWindow("Clipping in a Polygon Window");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}