#include<GL/glut.h>

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Assignment-01");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}