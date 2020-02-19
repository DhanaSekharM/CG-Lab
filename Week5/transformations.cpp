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
int translation_m[4][4]; 
float res[1][4];

void matrixMultiply(float co_ordinates[][4])
{
    int x, i, j; 
    int m1 = 1, m2 = 4, n1 = 4, n2 = 4;
    for (i = 0; i < m1; i++)  
    { 
        for (j = 0; j < n2; j++)  
        { 
            res[i][j] = 0; 
            for (x = 0; x < m2; x++)  
            { 
                *(*(res + i) + j) += *(*(co_ordinates + i) + x) * 
                                     *(*(translation_m + x) + j); 
            } 
        } 
    } 
    for (i = 0; i < m1; i++)  
    { 
        for (j = 0; j < n2; j++)  
        { 
            cout << *(*(res + i) + j) << " "; 
        } 
        cout << "\n"; 
    } 

}

void translateCube()
{
    float co_ordinates[1][4];
    co_ordinates[0][0] = 0.5, co_ordinates[0][1] = -0.5, co_ordinates[0][2] = 0.5, co_ordinates[0][3] = 1;
    
    // matrixMultiply(co_ordinates, true);
    // drawCube(0.5, true);
}

void drawCube(float x, bool translate)
{
    float xt = 0.0, yt = 0.0, zt = 0.0;
    if(translate)
    {
        xt = translation_m[3][0];
        yt = translation_m[3][1];
        zt = translation_m[3][2];
    }
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

void drawPyramid(bool translate)
{
    float xt = 0.0, yt = 0.0, zt = 0.0;
    if(translate)
    {
        xt = translation_m[3][0];
        yt = translation_m[3][1];
        zt = translation_m[3][2];
    }

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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho( -5, 5.0, -5.0, 5.0, -5, 5 );
    glRotatef( 45, 1.0, 0.0, 0.0 );
    glRotatef( 45, 0.0, 1.0, 0.0 );
    // ch = 1;
    if(ch == 1)
    {
        drawCube(0.5, false);
        drawCube(0.5, true);
    }
    else
    {
        drawPyramid(false);
        drawPyramid(true);
    }

    glFlush();
    glutSwapBuffers();


}

void acceptInput()
{
    cout<<"1. Cube 2.Pyramid\n";
    cin>>ch;
    cout<<"Enter translation co-ordinates\n";
    cin>>translation_m[3][0]>>translation_m[3][1]>>translation_m[3][2];

    for(int i = 0; i < 4; i++)
    {
        translation_m[i][i] = 1;
    }
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