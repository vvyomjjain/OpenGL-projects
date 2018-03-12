#include<gl/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,225.0);
}

void lineSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUAD_STRIP);
        glColor3f(0.0,0.4,0.2);

        glVertex2i(50,50);
        glVertex2i(50,100);
        glVertex2i(100,50);
        glVertex2i(100,100);
        glVertex2i(200,200);
        glVertex2i(210,150);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(800,450);
    glutCreateWindow("A simple line");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();

    return 0;
}
