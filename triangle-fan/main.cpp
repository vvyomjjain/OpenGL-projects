#include<gl/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,800.0,0.0,450.0);
}

void lineSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,0.4,0.2);
        glVertex2i(200, 100);
        glVertex2i(400, 100);
        glVertex2i(300, 400);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,0.2,0.2);
        glVertex2i(40, 40);
        glVertex2i(140, 40);
        glVertex2i(40, 140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.4,0.0,0.2);
        glVertex2i(500, 150);
        glVertex2i(700, 150);
        glVertex2i(600, 323);
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
