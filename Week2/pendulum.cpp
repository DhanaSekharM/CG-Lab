#include<GL/glut.h>
#include<iostream>
#include<algorithm>

using namespace std;

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
void drawLine(int x1, int y1, int x2, int y2)
{
    // // glPushMatrix();

    // int dx = x2 - x1;
    // int dy = y2- y1;

    // int steps = max(abs(dx), abs(dy));

    // float x_inc = dx/(float)steps;
    // float y_inc = dy/(float)steps;

    // // cout<<steps<<"\n";

    // int x = x1, y = y1;
    // glBegin(GL_POINTS);
    // for(int i = 1; i <= steps; i++) 
    // {
    //     glVertex2i(x, y);
    //     // cout<<x<<y;
    //     x += x_inc;
    //     y += y_inc;
    // }
    // glEnd();
    // // glPopMatrix();

    // int x1 = 0, y1 = 0, x2 = 20, y2 = 20;

    int dx = x2 - x1;
    int dy = y2- y1;

    int stepx = 1, stepy = 1;

    int fraction = 0, fraction_increment = 0;

    if(dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    if(dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }

    glBegin(GL_POINTS);

    if(dx >= dy) {
        fraction = 2*dy - dx;
        fraction_increment = 2*dy;
        while(x1 <= x2)
        {
            x1 += stepx;
            if(fraction >= 0)
            {
                y1 += stepy;
                fraction -= 2*dx; 
            }

            fraction += fraction_increment;
            glVertex2i(x1, y1);
        }

    } 
    else 
    {
        fraction = 2*dx - dy;
        fraction_increment = 2*dx;
        while(y1 <= y2)
        {
            y1 += stepy;
            if(fraction >= 0) 
            {
                x1 += stepx;
                fraction -= 2*dy;
            }
            fraction += fraction_increment;
            glVertex2i(x1, y1);
        }
    }

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
    int x1 = 0, y1 = r, x2 = 0, y2 = 4*r;
    drawLine(x1, y1, x2, y2);
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