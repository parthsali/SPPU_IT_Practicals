#include <GL/glut.h>
#include <math.h>

#define PIE 3.1415926535898

using namespace std;

void Koch(float xa, float ya, float xd, float yd, int n)
{
    float xc, yc, xb, yb, midx, midy;

    xb = (2 * xa + xd) / 3;
    xc = (2 * xd + xa) / 3;

    yb = (2 * ya + yd) / 3;
    yc = (2 * yd + ya) / 3;

    midx = xb + ((xc - xb) * cos((60 * PIE) / 180)) + ((yc - yb) * sin((60 * PIE) / 180));
    midy = yb - ((xc - xb) * sin((60 * PIE) / 180)) + ((yc - yb) * cos((60 * PIE) / 180));

    if (n > 0)
    {
        Koch(xa, ya, xb, yb, n - 1);
        Koch(xb, yb, midx, midy, n - 1);
        Koch(midx, midy, xc, yc, n - 1);
        Koch(xc, yc, xd, yd, n - 1);
    }
    else
    {
        glBegin(GL_LINE_STRIP);
        glClearColor(1, 1, 1, 0);
        glColor3f(1, 0, 0);
        glVertex2f(xa, ya);
        glColor3f(1, 1, 0);
        glVertex2f(xb, yb);
        glColor3f(1, 0.5, 0.3);
        glVertex2f(midx, midy);
        glColor3f(0, 1, 1);
        glVertex2f(xc, yc);
        glColor3f(1, 0, 1);
        glVertex2f(xd, yd);
        glEnd();
    }
}

void init()
{

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0, 0, 0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    int n = 3;
    float w = glutGet(GLUT_WINDOW_WIDTH);
    float h = glutGet(GLUT_WINDOW_HEIGHT);

    Koch(w * 0.5, h * 0.9, w * 0.3, h * 0.3, n);
    Koch(w * 0.7, h * 0.3, w * 0.5, h * 0.9, n);
    Koch(w * 0.3, h * 0.3, w * 0.7, h * 0.3, n);
    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 50);

    glutCreateWindow("Koch Curve");

    init();
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
