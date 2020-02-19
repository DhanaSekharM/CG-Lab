#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

void initGL()
{
    glClearColor(0, 0, 0, 0);
}

int ch;
float xt, yt, zt; 

void drawCube(float x, bool translate)
{
    float xt = 0.0, yt = 0.0, zt = 0.0;
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5+xt, -0.5+yt, 0.5+zt );
    glVertex3f(  0.5+xt,  0.5+yt, 0.5+zt );
    glVertex3f( -0.5+xt,  0.5+yt, 0.5+zt );
    glVertex3f( -0.5+xt, -0.5+yt, 0.5+zt );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5+xt, -0.5+yt, -0.5+zt );
    glVertex3f( 0.5+xt,  0.5+yt, -0.5+zt );
    glVertex3f( 0.5+xt,  0.5+yt,  0.5+zt );
    glVertex3f( 0.5+xt, -0.5+yt,  0.5+zt );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5+xt, -0.5+yt,  0.5+zt );
    glVertex3f( -0.5+xt,  0.5+yt,  0.5+zt );
    glVertex3f( -0.5+xt,  0.5+yt, -0.5+zt );
    glVertex3f( -0.5+xt, -0.5+yt, -0.5+zt );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5+xt,  0.5+yt,  0.5+zt );
    glVertex3f(  0.5+xt,  0.5+yt, -0.5+zt );
    glVertex3f( -0.5+xt,  0.5+yt, -0.5+zt );
    glVertex3f( -0.5+xt,  0.5+yt,  0.5+zt );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5+xt, -0.5+yt, -0.5+zt );
    glVertex3f(  0.5+xt, -0.5+yt,  0.5+zt );
    glVertex3f( -0.5+xt, -0.5+yt,  0.5+zt );
    glVertex3f( -0.5+xt, -0.5+yt, -0.5+zt );
    glEnd();
}

void drawPyramid()
{
    float xt = 0.0, yt = 0.0, zt = 0.0;

    glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f+xt, 1.0f+yt, 0.0f+zt);
      glVertex3f(-1.0f+xt, -1.0f+yt, 1.0f+zt);
      glVertex3f(1.0f+xt, -1.0f+yt, 1.0f+zt);
 
      // Right
      glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f(0.0f+xt, 1.0f+yt, 0.0f+zt);
      glVertex3f(1.0f+xt, -1.0f+yt, 1.0f+zt);
      glVertex3f(1.0f+xt, -1.0f+yt, -1.0f+zt);
 
      // Back
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f+xt, 1.0f+yt, 0.0f+zt);
      glVertex3f(1.0f+xt, -1.0f+yt, -1.0f+zt);
      glVertex3f(-1.0f+xt, -1.0f+yt, -1.0f+zt);
 
      // Left
      glColor3f(1.0f,1.0f,1.0f); 
      glVertex3f( 0.0f+xt, 1.0f+yt, 0.0f+zt);
      glVertex3f(-1.0f+xt,-1.0f+yt,-1.0f+zt);
      glVertex3f(-1.0f+xt,-1.0f+yt, 1.0f+zt);
   glEnd();
}

void drawPyramidX()
{
    float cost = cos(xt), sint = sin(xt);


    glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f*cost + 0.0f*sint, -1.0f*sint + 0.0f*cost);
      glVertex3f(-1.0f, -1.0f*cost + 1.0*sint, 1.0f*sint + 1.0*cost);
      glVertex3f(1.0f, -1.0f*cost+1.0*sint, 1.0f*sint+1.0*cost);
 
      // Right
      glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f( 0.0f, 1.0f*cost + 0.0f*sint, -1.0f*sint + 0.0f*cost);
      glVertex3f(1.0f, -1.0f*cost + 1.0*sint, 1.0f*sint + 1.0*cost);
      glVertex3f(1.0f, -1.0f*cost-1.0*sint, 1.0f*sint-1.0*cost);
 
      // Back
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f( 0.0f, 1.0f*cost + 0.0f*sint, -1.0f*sint + 0.0f*cost);
      glVertex3f(1.0f, -1.0f*cost-1.0*sint, 1.0f*sint-1.0*cost);
      glVertex3f(-1.0f, -1.0f*cost-1.0*sint, 1.0f*sint-1.0*cost);
 
      // Left
      glColor3f(1.0f,1.0f,1.0f); 
      glVertex3f( 0.0f, 1.0f*cost + 0.0f*sint, -1.0f*sint + 0.0f*cost);
      glVertex3f(-1.0f, -1.0f*cost-1.0*sint, 1.0f*sint-1.0*cost);
      glVertex3f(-1.0f, -1.0f*cost+1.0*sint, 1.0f*sint+1.0*cost);
   glEnd();
}

void drawPyramidY()
{
   
    float cost = cos(yt), sint = sin(yt);
    glRotatef(yt, 0, 1, 0);
    glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0);
 
      // Back
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 1.0f+yt, 0.0f+zt);
      glVertex3f(1.0f, -1.0f+yt, -1.0f+zt);
      glVertex3f(-1.0f, -1.0f+yt, -1.0f+zt);
 
      // Left
      glColor3f(1.0f,1.0f,1.0f); 
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();
}

void drawPyramidZ()
{
   
    float cost = cos(yt), sint = sin(yt);
    glRotatef(xt, 0, 0, 1);
    glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0);
 
      // Back
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 1.0f+yt, 0.0f+zt);
      glVertex3f(1.0f, -1.0f+yt, -1.0f+zt);
      glVertex3f(-1.0f, -1.0f+yt, -1.0f+zt);
 
      // Left
      glColor3f(1.0f,1.0f,1.0f); 
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho( -5, 5.0, -5.0, 5.0, -5, 5 );
    glRotatef( 45, 1.0, 0.0, 0.0 );
    glRotatef( 45, 0.0, 1.0, 0.0 );
    
    drawPyramid();
    // drawPyramidX();
    drawPyramidY();
    // drawPyramidZ();

    glFlush();
    glutSwapBuffers();


}

void acceptInput()
{
    cout<<"Enter rotation angles(x, y, z)\n";
    cin>>xt>>yt>>zt;

    xt = 3.14*xt/180;
    // yt = 3.14*xt/180;
    // zt = 3.14*xt/180;
}

int main(int argc, char** argv)
{
    acceptInput();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Translation");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();

    return 0;
}