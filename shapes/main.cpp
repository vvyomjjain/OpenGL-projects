#include<gl/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400.0,400.0,-300.0,300.0);
}

void lineSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.5);

    glBegin(GL_LINES);
    glVertex2i(-400, 0);
    glVertex2i(400,0);

    glBegin(GL_LINES);
    glVertex2i(0,400);
    glVertex2i(0,-400);

    glEnd();

    glMatrixMode (GL_MODELVIEW);
    glBegin(GL_TRIANGLES);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2i(300, 100);
        glVertex2i(350, 100);
        glVertex2i(325, 150);

    glTranslatef (-200.0, -50.0, 0.0); // Set translation parameters.
    glColor3f (0.0, 0.0, 1.0);
        glVertex2i(300, 100);
        glVertex2i(350, 100);
        glVertex2i(325, 150);

    glLoadIdentity ( ); // Reset current matrix to identity.

    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("Rotation by 90");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();

    return 0;
}
