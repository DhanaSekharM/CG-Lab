#include<GL/glut.h>
#include<math.h>
#include<algorithm>
#include<iostream>

using namespace std;
void initGL()
{
    glClearColor(0, 0, 0, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( -500, 500.0, -500.0,500.0 );
    int x1 = 20, y1 = 99, x2 = -20, y2 = -99;

    int dx = x2 - x1;
    int dy = y2- y1;

    int steps = max(abs(dx), abs(dy));

    float x_inc = dx/(float)steps;
    float y_inc = dy/(float)steps;

    // cout<<steps<<"\n";

    int x = x1, y = y1;
    glBegin(GL_POINTS);
    for(int i = 1; i <= steps; i++) 
    {
        glVertex2i(x, y);
        // cout<<x<<y;
        x += x_inc;
        y += y_inc;
    }
    glEnd();
    glFlush();

}

int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutCreateWindow("DDA");
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}