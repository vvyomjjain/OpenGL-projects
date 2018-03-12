#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
    glutSwapBuffers();
}

void button(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)

	{
        glColor3f( 1.0, 1.0, 1.0 );
        glMatrixMode(GL_MODELVIEW);
        glBegin(GL_POINTS);
        glPointSize(4);
        printf("We go click!");
        glVertex2i(x, y);
        glEnd();
        glFlush();
        //glutSwapBuffers();
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Mouse Click");
    glutMouseFunc(button);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
