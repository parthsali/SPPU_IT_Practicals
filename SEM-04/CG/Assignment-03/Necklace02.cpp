#include<iostream>
#include<GL/glut.h>

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -200, 300);
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

void displayPoint(float x, float y) {
    // glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

}


void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    //Center Circle
    drawCircle(0, 0, 70);


    //Left Side Circles
    drawCircle(-80, 40, 20);
    drawCircle(-112, 65, 20);
    drawCircle(-140, 95, 20);
    drawCircle(-160, 130, 20);
    drawCircle(-170, 170, 20);
    drawCircle(-180, 210, 20);

    //Right Side Circles
    drawCircle(80, 40, 20);
    drawCircle(112, 65, 20);
    drawCircle(140, 95, 20);
    drawCircle(160, 130, 20);
    drawCircle(170, 170, 20);
    drawCircle(180, 210, 20); 

    // Lower circles

    drawCircle(0, -90, 20);
    drawCircle(-40, -82, 20);
    drawCircle(40, -82, 20);

    // Last circle
    drawCircle(0, -130, 20);


    


    // Right side Circles
    
    
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