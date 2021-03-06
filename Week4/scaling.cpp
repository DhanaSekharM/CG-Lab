#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void initGL()
{
    glClearColor(0, 0, 0, 0);
}

int lx1, lx2, ly1, ly2, cx, cr, pfaces, ch, xt, yt, sx, sy;

void drawPolygon(int faces, int xt, int yt)
{
    float theta = 360.0/faces;
    int len = 50;
    glBegin(GL_POLYGON);
    // cout << theta << "\n";
    for(int i = 1; i <= faces; i++)
    {
        float inp_ang = theta*i*3.14/180;
        glVertex2f(50*cos(inp_ang)*xt, 50*sin(inp_ang)*yt);
        // cout<<cos(inp_ang)<<"\n";
    }
    glEnd();
}

void drawCirclePoints(int x, int y, int xt, int yt)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xt, y + yt);
    glVertex2i(y + xt, x + yt);
    glVertex2i(y + xt, -x + yt);
    glVertex2i(-x + xt, y + yt);
    glVertex2i(-x + xt, -y + yt);
    glVertex2i(-y + xt, -x + yt);
    glVertex2i(-y + xt, x + yt);
    glVertex2i(x + xt, -y + yt);
    glEnd();

}

void drawCircle(int xc, int yc, int r, int sx, int sy)
{
    int x = 0, y = r ;
    drawCirclePoints(x, y, 0, 0);
    int d = 3 - 2*r;

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
        drawCirclePoints(x, y, 0, 0);

    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D( -500, 500.0, -500.0, 500.0 );

    switch(ch)
    {
        case 1:
            glBegin(GL_LINES);
            glVertex2f(lx1, ly1);
            glVertex2f(lx2, ly2);
            glEnd();
            cout<<sx << sy <<"\n";
            glBegin(GL_LINES);
            glVertex2f(lx1*sx, ly1*sy);
            glVertex2f(lx2*sx, ly2*sy);
            glEnd();
            break;
        case 2:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            drawPolygon(pfaces, 1, 1);
            drawPolygon(pfaces, sx, sy);
            // drawPolygon(pfaces)
            break;
        case 3:
            drawCircle(0, 0, cr, 0, 0);
            drawCircle(0, 0, cr*sx, sx, sy);
            break;
    }
    glFlush();
}

void acceptInput()
{
    cout << "1.Line 2.Polygon 3.Circle\n";
    cin >> ch;

    switch(ch) 
    {
        case 1:
            cout<<"Enter endpoints as x1 y1 x2 y2\n";
            cin >> lx1 >> ly1 >> lx2 >> ly2;
            break;
        case 2:
            cout<<"Enter number of faces\n";
            cin >> pfaces;
            break;
        case 3:
            cout << "Enter radius of circle\n";
            cin >> cr;
            break;
    }

    cout << "Enter scaling factor\n";
    cin >> sx >> sy;
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