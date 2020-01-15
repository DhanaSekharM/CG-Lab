#include<GL/glut.h>
#include<math.h>
#include<algorithm>
#include<iostream>

using namespace std;
void initGL()
{
    glClearColor(0, 0, 0, 0);
}

void drawLine(int x1, int y1, int x2, int y2)
{
    glPushMatrix();

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
    glPopMatrix();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D( -500, 500.0, -500.0,500.0 );

    //draw rows
    int height = 100, x_pos = 400, x_neg = -400, y = -400;
    for(int i = 0; i <= 8; i++)
    {
        drawLine(x_neg, y, x_pos, y);
        y += height;
    }

    int width = 100, y_pos = 400, y_neg = -400, x = -400;
    for(int i = 0; i <= 8; i++)
    {
        drawLine(x, y_pos, x, y_neg);
        x += width;
    }

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