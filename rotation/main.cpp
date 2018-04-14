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

    glMatrixMode (GL_MODELVIEW);
    glColor3f (0.0, 0.0, 1.0);
    glRecti (50, 100, 200, 150); // Display blue rectangle.
    glColor3f (1.0, 0.0, 0.0);
    glLoadIdentity ( ); // Reset current matrix to identity.
    glRotatef (90.0, 0.0, 0.0, 1.0); // Set 90-deg. rotation about z axis.
    glRecti (50, 100, 200, 150); // Display red, rotated rectangle.
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
