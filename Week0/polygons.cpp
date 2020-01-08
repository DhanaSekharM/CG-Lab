#include <GL/glut.h>

void initGL()
{
    glClearColor(0, 0, 0, 1);
}

void idle()
{
    glutPostRedisplay();
}

GLfloat angle = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-0.1, 0.1, 0.0);
    glRotatef(angle, 0, 0, 1);
    //Triangle
    glBegin(GL_TRIANGLES);
    // glColor3f(1, 1, 1);
    glVertex2f(0.1, -0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.0, 0.2);
    glEnd();
    glPopMatrix();

    //Trapezium
    glPushMatrix();
    glTranslatef(0.4, 0.4, 0);
    glRotatef(angle, 0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.1, 0.3);
    glVertex2f(-0.1, 0.3);
    glEnd();
    glPopMatrix();

    //Pentagon
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef(angle, 1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, -0.3);
    glVertex2f(-0.1, -0.3);
    glVertex2f(-0.1, -0.1);
    glEnd();

    glFlush();

    angle += 0.002;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Polygons");
    glutInitWindowPosition(20, 20);
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    glutIdleFunc(idle); // Register callback handler if no other event
    initGL();
    glutMainLoop();
    return 0;
}
