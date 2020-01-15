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
    int x1 = 0, y1 = 0, x2 = 20, y2 = 20;

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