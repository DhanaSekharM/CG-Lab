#include <stdio.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glx.h>

int n;

void initGL()
{
    glClearColor(0, 0, 0, 0);
}

void drawSquares(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int levels)
{
	if(levels == 1)
	{
		glVertex2f((x2 + x3 + x4)/3, (y2 + y3 + y4)/3);
		printf("%f %f\n", (x2 + x3 + x4)/3, (y2 + y3 + y4)/3);
		glVertex2f((x3 + x4 + x1)/3, (y3 + y4 + y1)/3);
		printf("%f %f\n", (x3 + x4 + x1)/3, (y3 + y4 + y1)/3);
		glVertex2f((x4 + x1 + x2)/3, (y4 + y1 + y2)/3);
		printf("%f %f\n", (x4 + x1 + x2)/3, (y4 + y1 + y2)/3);
		glVertex2f((x1 + x2 + x3)/3, (y1 + y2 + y3)/3);
		printf("%f %f\n", (x1 + x2 + x3)/3, (y1 + y2 + y3)/3);
	}
	else
	{
		// 1
		drawSquares(x1, y1, (x4 + x1 + x2)/3, y1,(x4 + x1 + x2)/3, (y4 + y1 + y2)/3, x1, (y4 + y1 + y2)/3, levels-1);
		// 2
		drawSquares((x1 + x2 + x3)/3, y2, x2, y2, x2, (y1 + y2 + y3)/3,(x1 + x2 + x3)/3, (y1 + y2 + y3)/3, levels-1);
		// 3
		drawSquares((x2 + x3 + x4)/3, (y2 + y3 + y4)/3, x3, (y2 + y3 + y4)/3, x3, y3, (x2 + x3 + x4)/3, y3, levels-1);
		// 4
		drawSquares(x4, (y3 + y4 + y1)/3, (x3 + x4 + x1)/3, (y3 + y4 + y1)/3, (x3 + x4 + x1)/3, y4, x4, y4, levels-1);

        // drawSquares()
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);

	glBegin(GL_QUADS);

	drawSquares(900, 900, -900, 900, -900, -900, 900, -900, n);

	glEnd();
	glFlush();	
}

int main(int argc, char **argv)
{
	printf("Enter the number of revursive levels\n");
	scanf("%d", &n);
	if(n < 1)
	{
		printf("The recursive levels should be greater than 0\n");
		return 0;
	}
	glutInit(&argc, argv);
	glutCreateWindow("Sierpinski square");
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}