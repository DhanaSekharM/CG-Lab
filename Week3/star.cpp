/*
LMB - exit
RMB - draw a star at the clicked position
Key s - increase the size of the next star
Key r - decrease the size of the next star
*/
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void initGL()
{
    glClearColor(0, 0, 0, 1);
}

// int scaling = ;
float x = 0.0, y = 0.0, scaling = 1.0;

void drawUpperTriangle()
{
    glVertex2f(0, 0.3);
    glVertex2f(0.2, -0.1);
    glVertex2f(-0.2, -0.1);
}

void drawLowerTriangle()
{
    glVertex2f(0, -0.3);
    glVertex2f(0.2, 0.1);
    glVertex2f(-0.2, 0.1);
}

void drawStar()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scaling, scaling, scaling);
    glBegin(GL_TRIANGLES);
    drawUpperTriangle();
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glTranslatef(x, y, 0);
    glScalef(scaling, scaling, scaling);
    glBegin(GL_TRIANGLES);
    drawLowerTriangle();
    glEnd();
    glPopMatrix();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawStar();
}

void mouseHandler(int button, int state, int xi, int yi)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x = (xi-150)/(float)150;
        y = -(yi-150)/(float)150;
        // printf("%f, %f\n", x, y);
        drawStar();
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glutDestroyWindow(glutGetWindow());
    }
}

void keyBoardHandler(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        scaling += 0.2;
        break;
    case 'r':
        scaling -= 0.2;
        if(scaling <= 0) scaling = 0.1;
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
    glutMouseFunc(mouseHandler);
    glutKeyboardFunc(keyBoardHandler);
    initGL();
    glutMainLoop();
    return 0;
}