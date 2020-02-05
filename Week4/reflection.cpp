#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void initGL()
{
    glClearColor(0, 0, 0, 0);
}

int lx1, lx2, ly1, ly2, cx, cr, pfaces, ch, xt, yt;

void drawPolygon(int faces, int xt, int yt)
{
    float theta = 360.0/faces;
    int len = 50;
    glBegin(GL_POLYGON);
    // cout << theta << "\n";
    for(int i = 1; i <= faces; i++)
    {
        float inp_ang = theta*i*3.14/180;
        float x = 50*cos(inp_ang), y = 50*sin(inp_ang);
        if(xt) {
            y = -y;
        }
        if(yt) {
            x = -x;
        }
        glVertex2f(x, y);
        // cout<<cos(inp_ang)<<"\n";
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D( -500, 500.0, -500.0, 500.0 );
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    drawPolygon(pfaces, 0, 0);
    drawPolygon(pfaces, 1, 0);
    drawPolygon(pfaces, 0, 1);
        
    glFlush();
}

void acceptInput()
{
    cout<<"Enter number of faces\n";
    cin >> pfaces;
}

int main(int argc, char** argv)
{
    acceptInput();
    glutInit(&argc, argv);
    glutCreateWindow("Translation");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();

    return 0;
}