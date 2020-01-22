#include<GL/glut.h>
#include<iostream>
int time1 = 0;

void initGL()
{
    glClearColor(0, 0, 0, 0);
}

void idle()
{
    int cur_time = glutGet(GLUT_ELAPSED_TIME);
    int diff = cur_time - time1;
    if(diff > 100) 
    {
       glutPostRedisplay();
        time1 = cur_time;
    }
    
    
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

int height = 0;
int up = 0;
int max = 400;
int min = -400;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

    int xc = 0, yc = 450, r = 100;
    int x = 0, y = r;
    int d = 3 - 2*r;

    glPushMatrix();
    if(yc+height >= max)
    {
        up = 0;
    }
    if(yc+height <= min)
    {
        up = 1;
    }
    if(up == 0)
    {
        height -= 50;
    }
    else 
    {
        height += 50;
    }
    
    glTranslatef(xc, yc+height, 0);
    

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
    glutIdleFunc(idle);
    initGL();
    glutMainLoop();
    return 0;
}