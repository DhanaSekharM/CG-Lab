#include<GL/glut.h>

void initGl()
{
    glClearColor(0,0,0,1);
}

int choice;

void menu(int num)
{
    choice = num;
    glutPostRedisplay();
}

void createMenu()
{
    glutCreateMenu(menu);
    glutAddMenuEntry("Wire Teapot", 1);
    glutAddMenuEntry("Solid Teapot", 2);
    glutAddMenuEntry("Diagonal Wire Teapot", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    switch(choice)
    {
        case 1: 
            glPushMatrix();
            glColor3f(0, 0, 1);
            glutWireTeapot(0.5);
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glColor3f(0, 1, 1);
            glutSolidTeapot(0.5);
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            glColor3f(0, 1, 1);
            glutSolidTeapot(0.5);
            glPopMatrix();
            break;
    }

    glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Menu");
    createMenu();
    glutDisplayFunc(display);
    initGl();
    glutMainLoop();
    return 1;
}