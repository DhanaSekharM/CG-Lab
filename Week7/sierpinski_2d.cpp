#include<GL/glut.h>
#include<iostream>
#include<stdio.h>

using namespace std;

void initGl()
{
    glClearColor(0, 0, 0 ,1);
    glClearDepth(1.0);
}

int rec;

float x1 = 0.0, y1 = 0.0, x2 = 0.6, y2 = 0, x3 = 0.3, y3 = 0.5196;

void drawSierpinski(float x1_t, float y1_t, float x2_t, float y2_t, float x3_t, float y3_t, int r)
{
    if(r > 0) 
    {
        drawSierpinski(x1_t, y1_t, (x2_t+x1_t)/2, (y2_t+y1_t)/2, (x3_t+x1_t)/2, (y3_t+y1_t)/2, r-1);
        drawSierpinski((x1_t+x2_t)/2, (y1_t+y2_t)/2, x2_t, y2_t, (x3_t+x2_t)/2 , (y3_t + y2_t)/2, r-1);
        drawSierpinski((x1_t+x3_t)/2, (y1_t+y3_t)/2, (x2_t+x3_t)/2, (y2_t+y3_t)/2, x3_t, y3_t, r-1);
    }

    if(r == 0)
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(x1_t, y1_t);
        glVertex2f(x2_t, y2_t);
        glVertex2f(x3_t, y3_t);
        glEnd();
    }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // gluOrtho2D(-10, 10, -10, 10);
    drawSierpinski(x1, y1, x2, y2, x3, y3, rec);
    glFlush();

}

void acceptInput()
{
    cout<<"Enter r\n";
    cin>>rec;
}

int main(int argc, char **argv)
{
    acceptInput();
    glutInit(&argc, argv);
    glutCreateWindow("Sierpinski");
    glutDisplayFunc(display);
    initGl();
    glutMainLoop();
    return 0;
}

