#include<GL/glut.h>
#include <string>

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
    
}

void displayPoint(float x, float y) {
    glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

}

void drawLine(int x1, int y1, int x2, int y2,char line = 'A') {
    
    int P;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;
    

    int x_change = x1 > x2 ? -1 : 1;
    int y_change = y1 > y2 ? -1 : 1;

    displayPoint(x, y);

    if (dx == 0) {
       
        glBegin(GL_POINTS);
        for(int i=0; i < abs(dy); i++) {
            y += y_change;
           if (line == 'B') {
                if (i % 3 == 0) {
                    glVertex2f(x, y);
                }
            }
            else if(line == 'C') {
                if (i % 7 == 0) {
                    glVertex2f(x, y);
                }
            }
            else {
                glVertex2f(x, y);
            }
        }
        glEnd();
        glFlush();
        return;
    }
    if (dy == 0) {
    
        glBegin(GL_POINTS);
        for(int i=0; i < abs(dx); i++) {
            x += x_change;
            if (line == 'B') {
                if (i % 3 == 0) {
                    glVertex2f(x, y);
                }
            }
            else if(line == 'C') {
                if (i % 7 == 0) {
                    glVertex2f(x, y);
                }
            }
            else {
                glVertex2f(x, y);
            }
        }
        glEnd();
        glFlush();
        return;
    }
   
    glBegin(GL_POINTS);
    if (dx > dy) {
        P = 2 * dy - dx;
        for (int i = 0; i < dx; i++) {
            if (P > 0) {
                y += y_change;
                P += 2 * dy - 2 * dx;
            }
            else {
                P += 2 * dy;
            }
            x += x_change;
            if (line == 'B') {
                if (i % 3 == 0) {
                    glVertex2f(x, y);
                }
            }
            else if(line == 'C') {
                if (i % 7 == 0) {
                    glVertex2f(x, y);
                }
            }
            else {
                glVertex2f(x, y);
            }
        }

    }
    else {
        P = 2 * dx - dy;
        for (int i = 0; i < dy; i++) {
            if (P > 0) {
                x += x_change;
                P += 2 * dx - 2 * dy;
            }
            else {
                P += 2 * dx;
            }
            y += y_change;
            if (line == 'B') {
                if (i % 3 == 0) {
                    glVertex2f(x, y);
                }
            }
            else if(line == 'C') {
                if (i % 7 == 0) {
                    glVertex2f(x, y);
                }
            }
            else {
                glVertex2f(x, y);
            }
        
        }
    }
    glEnd();
    glFlush();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // A = SIMPLE LINE
    // B = DOTTED LINE
    // C = DASHED LINE
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