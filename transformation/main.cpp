#include<gl/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400.0,400.0,-300.0,300.0);
}

void translation(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode (GL_MODELVIEW);
    glColor3f (0.0, 0.0, 1.0);
    glRecti (50, 100, 200, 150); // Display blue rectangle.
    glColor3f (1.0, 0.0, 0.0);
    glTranslatef (-200.0, -50.0, 0.0); // Set translation parameters.
    glRecti (50, 100, 200, 150); // Display red, translated rectangle.
    glLoadIdentity ( ); // Reset current matrix to identity.

    glEnd();
    glFlush();
}

void scaling(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode (GL_MODELVIEW);
    glColor3f (0.0, 0.0, 1.0);
    glRecti (50, 100, 200, 150); // Display blue rectangle.
    glColor3f (1.0, 0.0, 0.0);
    glScalef (-0.5, 1.0, 1.0); // Set scale-reflection parameters.
    glRecti (50, 100, 200, 150); // Display red, transformed rectangle.
    glLoadIdentity ( ); // Reset current matrix to identity.

    glEnd();
    glFlush();
}

void rotation(void){
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
    glutCreateWindow("Basic Transformations");

    int c = 0;
    printf("Welcome to the Transformation world!\n\n");
    printf("Tell us what would you like us to demonstrate:\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");

    scanf("%d",&c);

    switch(c){
    case 1:
        init();
        glutDisplayFunc(translation);
        glutMainLoop();
        break;

    case 2:
        init();
        glutDisplayFunc(scaling);
        glutMainLoop();
        break;

    case 3:
        init();
        glutDisplayFunc(rotation);
        glutMainLoop();
        break;
    }

    return 0;
}
