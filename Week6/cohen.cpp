#include<GL/glut.h>
#include<iostream>
#include<stdio.h>

using namespace std;

void initGl()
{
    glClearColor(0, 0, 0, 1);
}

int x_min = 0, y_min = 0, x_max = 400, y_max = 400;
float x1, y1, x2, y2;

int inside = 0, lef = 1, righ = 2, top = 8, bottom = 4;

int calculateCode(float x, float y)
{
    int code = 0;

    if(x < x_min) code |= lef;
    if(x > x_max) code |= righ;
    if(y < y_min) code |= bottom;
    if(y > y_max) code |= top;

    return code;
}

void clipLine()
{
    float x1_t = x1, y1_t = y1, x2_t = x2, y2_t = y2;
    float slope = (x2-x1)/(y2-y1);

    bool in = true;

    while(true)
    {
        int code1 = calculateCode(x1_t, y1_t);
        int code2 = calculateCode(x2_t, y2_t);
        if(code1 == 0 && code2 == 0)
        {
            break;
        }
        else if(code1 & code2 != 0)
        {
            in = false;
            break;
        }
        else
        {
            int code;
            float x, y;

            if(code1 != 0)
            {
                x = x1_t;
                y = y1_t;
                code = code1;
            }
            else
            {
                x = x2_t;
                y = y2_t;
                code = code2;
            }
            // Find intersection point; 
            // using formulas y = y1 + slope * (x - x1), 
            // x = x1 + (1 / slope) * (y - y1) 
            if(code & top)
            {
                x = x1 + (1/slope) * (y_max - y); 
                y = y_max;
            } 
            else if(code & bottom)
            {
                x = x1 + (1/slope) * (y_min - y); 
                y = y_min; 
            }
            else if(code & righ)
            {
                x = x_max;
                y = y1 + slope * (x_max - x1);
            } else if(code & lef)
            {
                x = x_min;
                y = y1 + slope * (x_min - x1);
            }

            if(code == code1)
            {
                x1_t = x;
                y1_t = y;
            }
            else
            {
                x2_t = x;
                y2_t = y;
            }
        }
        
    }

    if(in)
    {
        x1 = x1_t;
        y1 = y1_t;
        x2 = x2_t;
        y2 = y2_t;
    }
    else
    {
        x1 = x_min;
        y1 = y_min;
        x2 = x_min;
        y2 = y_min;
    }
    


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    //clipping window
    glBegin(GL_LINES);
    //bottom
    glVertex2f(x_min, y_min);
    glVertex2f(x_max, y_min);
    //left
    glVertex2f(x_min, y_min);
    glVertex2f(x_min, y_max);
    //top
    glVertex2f(x_min, y_max);
    glVertex2f(x_max, y_max);
    //right
    glVertex2f(x_max, y_max);
    glVertex2f(x_max, y_min);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    clipLine();

    //draw clipped line
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glFlush();
}

void acceptInput()
{
    cout<<"Enter (x1, y1), (x2, y2)\n";
    cin>>x1>>y1>>x2>>y2;
}

int main(int argc, char **argv)
{
    acceptInput();
    glutInit(&argc, argv);
    glutCreateWindow("Clip");
    glutDisplayFunc(display);
    initGl();
    glutMainLoop();
    return 1;
}