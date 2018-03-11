#include<gl/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}

void lineSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.4,0.2);

    glBegin(GL_LINES);
        glVertex2i(60,20);
        glVertex2i(60,120);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(100,20);
        glVertex2i(100,120);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(30,90);
        glVertex2i(130,90);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(30,50);
        glVertex2i(130,50);
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
