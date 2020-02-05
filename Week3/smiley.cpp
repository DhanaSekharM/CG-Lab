/*
key a = clockwise rotation
key b = anti-clockwise rotation
key c = increase size
key d = decrease size
key e = move right
key r = reset to original
key x = exit
*/

#include <GL/glut.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void initGL()
{
    glClearColor(0, 0, 0, 1);
}

void idle()
{
    glutPostRedisplay();
}

// int scaling = ;
float x = 0.0, y = 0.0, scaling = 1.0, angle = 0.0;

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

void drawCircle(int xc, int yc, int r)
{

    // int xc = -100, yc = -100, r = 100;
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
    // glFlush();

}

void drawSemiCirclePoints(int x, int y)
{
    glBegin(GL_POINTS);
    // glVertex2i(x, y);
    // glVertex2i(y, x);
    glVertex2i(y, -x);
    // glVertex2i(-x, y);
    glVertex2i(-x, -y);
    glVertex2i(-y, -x);
    // glVertex2i(-y, x);
    glVertex2i(x, -y);
    glEnd();

}

void drawSemiCircle(int xc, int yc, int r)
{

    // int xc = -100, yc = -100, r = 100;
    int x = 0, y = r;
    int d = 3 - 2*r;

    glPushMatrix();
    glTranslatef(xc, yc, 0);
    drawSemiCirclePoints(x, y);

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
        drawSemiCirclePoints(x, y);

    }
    glPopMatrix();
}

void drawFace()
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scaling, scaling, scaling);
    // printf("%f", x);
    //face
    drawCircle(0, 0, 400);

    //nose

    drawCircle(0, -50, 40);

    //left eye
    drawCircle(200, 150, 75);
    //left eyeball
    glPushMatrix();
    glTranslatef(200, 150, 0);
    glRotatef(angle, 0, 0, 1);
    drawCircle(10, 10, 25);
    glPopMatrix();

    //right eye
    drawCircle(-200, 150, 75);
    //right eyeball
    glPushMatrix();
    glTranslatef(-200, 150, 0);
    glRotatef(angle, 0, 0, 1);
    drawCircle(10, 10, 25);
    glPopMatrix();
    // drawCircle(-200, 125, 25);

    //smile
    drawSemiCircle(0, 0, 300);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000.0, 1000.0, -1000.0, 1000.0);
    drawFace();
    glFlush();
}

void mouseHandler(int button, int state, int xi, int yi)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x = (xi-150)/(float)150;
        y = -(yi-150)/(float)150;
        printf("%f, %f\n", x, y);
        // drawStar();
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glutDestroyWindow(glutGetWindow());
    }
}

void keyBoardHandler(unsigned char key, int xi, int yi)
{
    switch (key)
    {
    case 'a':
        angle += 2;
        break;
    case 'b':
        angle -= 2;
        break;
    
    case 'c':
        scaling += 0.2;
        break;
    case 'd':
        scaling -= 0.2;
        if(scaling <=0 ) scaling = 1.0;
        break;
    case 'e':
        // printf("sa");
        x = x+50;
        break;
    case 'f':
        // printf("sa");
        x = x-50;
        break;
    case 'r':
        x = 0;
        scaling = 1.0;
        break;
    case 'x':
        glutDestroyWindow(glutGetWindow());
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Star");
    // glutInitWindowSize(w, h);
    glutInitWindowPosition(0, 0);
    // glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    // glutMouseFunc(mouseHandler);
    glutKeyboardFunc(keyBoardHandler);
    glutIdleFunc(idle);
    initGL();
    glutMainLoop();
    return 0;
}