#include<GL/glut.h>
#include<iostream>

void initGL()
{
    glClearColor(0, 0, 0, 0);
}

void drawCirclePoints(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glVertex2i(y, x);
    glVertex2i(y, -x);
    glVertex2i(-x, y);
    glVertex2i(-x, -y);
    glVertex2i(-y, -x);
    glVertex2i(-y, x);
    glVertex2i(x, -y);
    glEnd();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

    int xc = -100, yc = -100, r = 100;
    int x = 0, y = r;
    int d = 3 - 2*r;

    glPushMatrix();
    glTranslatef(xc, yc, 0);
    drawCirclePoints(x, y);

    while(x <= y)
    {
        x++;

        if(d > 0)
        {
            y--;
            d = d + 4*(x-y) + 10;
        }
        else 
        {
            d += 4*x + 6;
        }
        drawCirclePoints(x, y);

    }
    glPopMatrix();
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Circle");
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(420, 420);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}