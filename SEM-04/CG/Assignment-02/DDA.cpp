#include<GL/glut.h>
#include<iostream>

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void displayPoint(float x, float y) {
    glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

}

void drawLine(float x1, float y1, float x2, float y2, char line = 'A') {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;

    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;

    float x = x1;
    float y = y1;

    displayPoint(x, y);
        for (int i = 0; i < steps; i++) {
        
            
            if (line == 'B') {
                if (i % 3 == 0) {
                   displayPoint(x, y);
                }
            }
            else if(line == 'C') {
                if (i % 7 == 0) {
                    displayPoint(x, y);
                }
            }
            else {
                displayPoint(x, y);
            }
            x += xInc;
        y += yInc;
        
    }
    
    glFlush();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // A SIMPLE LINE
    // B DOTTED LINE
    // C DASHED LINE
    drawLine(10, 10, 490, 490, 'A');
    drawLine(10, 250, 490, 250, 'B');
    drawLine(250, 490, 250, 10, 'C');
    
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}