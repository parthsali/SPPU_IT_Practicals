#include<iostream>
#include<GL/glut.h>

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void drawCirclePoints(int centerX, int centerY, int x, int y, int colorOne, int colorTwo, int colorThree) {
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    glVertex2i(centerX + x, centerY + y);
    glColor3f(1, 0, 0.5);
    glVertex2i(centerX - x, centerY + y);
    glColor3f(1, 0.5, 0);
    glVertex2i(centerX + x, centerY - y);
    glColor3f(0.5, 0, 1);
    glVertex2i(centerX - x, centerY - y);
    glColor3f(0, 0.5, 1);
    glVertex2i(centerX + y, centerY + x);
    glColor3f(1, 1, 0);
    glVertex2i(centerX - y, centerY + x);
    glColor3f(1, 0, 1);
    glVertex2i(centerX + y, centerY - x);
    glColor3f(0, 1, 1);
    glVertex2i(centerX - y, centerY - x);
    
    glEnd();

}

void drawCircle(int centerX, int centerY, int radius, int colorOne=1, int colorTwo=1, int colorThree=1) {
    int x = 0;
    int y = radius;

    int P = 3 - 2 * radius;

    while (x <= y) {
        
        drawCirclePoints(centerX, centerY, x, y, colorOne, colorTwo, colorThree);

        if (P > 0) {
            P += 4 * (x - y) + 10;
            y--;
        }
        else {
            P += 4 * x + 6;
        }
        x++;

    }

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(250, 100, 90);
    drawCircle(150, 150, 70);
    drawCircle(350, 150, 70);

    
    drawCircle(90, 230, 55);
    drawCircle(410, 230, 55);

    drawCircle(60, 280, 40);
    drawCircle(440, 280, 40);

    drawCircle(35, 325, 30);
    drawCircle(465, 325, 30);

    drawCircle(20, 360, 20);
    drawCircle(480, 360, 20);

    drawCircle(15, 385, 15);
    drawCircle(485, 385, 15);

    drawCircle(10, 405, 10);
    drawCircle(490, 405, 10);
    
    drawCircle(10, 420, 10);
    drawCircle(490, 420, 10);

    drawCircle(10, 435, 10);
    drawCircle(490, 435, 10);
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(450, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("NeckLace Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
    
}