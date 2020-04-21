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
using namespace std;

void init()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  //rgba
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(-10, 10, -10, 10);
  //left, right, bottom, top
  // if center if (0,0) and radius is 10
  glMatrixMode(GL_MODELVIEW);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  // glPointSize(10.0);
  // glBegin(GL_POINTS);
  // glVertex2f(5, 5);
  // glVertex2f(-5, -5);
  // glEnd();

  // glBegin(GL_TRIANGLES);
  //   glVertex2f(0.0,5.0);
  //   glVertex2f(-4.0,-3.0);
  //   glVertex2f(4.0,-3.0);
  // glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(0.0, 5.0);
  glVertex2f(0.0, 0.0);
  glVertex2f(5.0, 0.0);
  glVertex2f(5.0, 5.0);
  glEnd();

  glFlush();
}

void displayMe()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glLoadIdentity();

  // glPointSize(10.0);
  // glBegin(GL_LINE_LOOP);
  //   glVertex2f(0.0,0.5);
  //   glVertex2f(0.0,0.0);
  //   glVertex2f(0.5,0.0);
  //   glVertex2f(0.5,0.5);
  // glEnd();

  glColor3f(1.0, 0.0, 0.0);
  // glBegin(GL_TRIANGLE_FAN);
  //   glVertex2f(-0.5,0.5);
  //   glVertex2f(-0.75,-0.5);
  //   glVertex2f(0.0,-0.5);
  //   // glVertex2f(-0.5,-0.75);
  //   glVertex2f(-0.75,-0.75);
  //   // glVertex2f(0.0,-0.75);
  // glEnd();

  glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.0, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.0, 0.5, 0.5);
    glVertex3f(0.0, 0.0, 0.5);

  glEnd();

  // glBegin(GL_POLYGON);
  //   glVertex3f(0.5, 0.0, 0.5);
  //   glVertex3f(0.5, 0.0, 0.0);
  //   glVertex3f(0.0, 0.5, 0.0);
  //   glVertex3f(0.0, 0.0, 0.5);
  // glEnd();

  GLint circle_points = 3000;
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<circle_points;i++){
      double angle = 2*3.1416*i/circle_points;
      glVertex2f(0.6*cos(angle), 0.6*sin(angle));
    }
  glEnd();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("SEE?");
  glutDisplayFunc(displayMe);
  // glutReshapeFunc(reshape);
  init();
  glutMainLoop();
  return 0;
}