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
    glVertex2i(-200,-150);
    glVertex2i(200,-150);

    glBegin(GL_LINES);
    glVertex2i(-150,200);
    glVertex2i(-150,-200);

    glEnd();

    glMatrixMode (GL_MODELVIEW);
    glColor3f (0.0, 0.0, 1.0);
    glRecti (-130, -150, -120, -100);
    glColor3f (1.0, 0.0, 0.0);
    glRecti (-100, -150, -90, -70);
    glColor3f (0.0, 1.0, 0.0);
    glRecti (-70, -150, -60, -50);
    glColor3f (0.0, 0.0, 1.0);
    glRecti (-40, -150, -30, -10);
    glColor3f (1.0, 0.0, 0.0);
    glRecti (-10, -150, 0, 70);
    glColor3f (0.0, 1.0, 0.0);
    glRecti (20, -150, 30, 50);
    glColor3f (0.0, 0.0, 1.0);
    glRecti (50, -150, 60, 100);
    glColor3f (1.0, 0.0, 0.0);
    glRecti (80, -150, 90, 120);
    glColor3f (0.0, 1.0, 0.0);
    glRecti (110, -150, 120, 150);
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
