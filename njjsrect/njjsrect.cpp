#include<windows.h>
#include<gl/gl.h>
#include <GL/glut.h>
#include<stdio.h>

GLsizei w = 1000;
GLsizei h = 1000;
int x1,y1,x2,y2;
int k = 0;
void start(){
    glViewport(0,0,w,h);
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	gluOrtho2D(0, 1000, 0, 1000);

}
void njs(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        x1=x;
        y1 = h - y;
        glutPostRedisplay();

    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        x2=x;
        y2 = h - y;
        glutPostRedisplay();

    }

}

void drawrectangle(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glLineWidth(10.0);
                                                                                                                                                                                                     glBegin(GL_LINE_LOOP);
    	glVertex2i(x1,y1);
		glVertex2i(x2,y1);
		glVertex2i(x2,y2);
		glVertex2i(x1,y2);
    glEnd();


    glutSwapBuffers();

}

void motion( int x, int y )
{
    x2 = x;
	y2 = h - y;
     glutPostRedisplay();
}
void Resize_window(GLsizei width,GLsizei height){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)width,0.0,(GLdouble)height);
	glViewport(0,0,width,height);
	w = width;
	h = height;
}
int main(int argc, char**argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(0,0);
	glutCreateWindow("Rectangle Drawing");
	glutMouseFunc(njs);
	glutMotionFunc(motion);
	glutReshapeFunc(Resize_window);
	start();
    glutDisplayFunc(drawrectangle);
    glutMainLoop();
    return 0;

}
