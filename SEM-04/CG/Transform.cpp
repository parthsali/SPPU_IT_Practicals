#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

#define rad (3.142 / 180)

GLfloat point[3][3];
GLfloat Transform[3][3];
int n;

void draw(GLfloat a[3][3])
{
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    glBegin(GL_POLYGON);
    for (i = 0; i < 3; i++)
    {
        glVertex2f(a[i][0], a[i][1]);
    }
    glEnd();
    glFlush();
}

void trans(GLfloat tx, GLfloat ty)
{
    for (int i = 0; i < n; i++)
    {
        point[i][0] += tx;
        point[i][1] += ty;
    }
    glColor3f(0.0, 1.0, 0.0);
    draw(point);
    glFlush();
}

void scale(GLfloat sx, GLfloat sy)
{

    for (int i = 0; i < n; i++)
    {
        point[i][0] *= sx;
        point[i][1] *= sy;
    }
    glColor3f(0.0, 0.0, 1.0);
    draw(point);
    glFlush();
}

void rot(float angle, GLfloat refx, GLfloat refy)
{
    angle = angle * rad;
    for (int i = 0; i < n; i++)
    {
        float x = point[i][0];
        float y = point[i][1];
        point[i][0] = refx + (x - refx) * cos(angle) - (y - refy) * sin(angle);
        point[i][1] = refy + (x - refx) * sin(angle) + (y - refy) * cos(angle);
    }
    draw(point);
}

void display()
{
    n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            point[i][j] = 0;
        }
    }
    point[0][0] = 0.0;
    point[0][1] = 0.0;
    point[1][0] = 100.0;
    point[1][1] = 0.0;
    point[2][0] = 50.0;
    point[2][1] = 100.0;

    draw(point);
    glFlush();
}

void ini()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(500, 0);
    glVertex2i(500, 1000);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(0, 500);
    glVertex2i(1000, 500);
    glEnd();
    glFlush();
}

void Menu(int c)
{
    if (c == 1)
    {
        trans(100, 100);
    }
    else if (c == 2)
    {
        trans(-100, -100);
    }
    else if (c == 4)
    {
        rot(-45.0f, 0.0f, 0.0f);
    }
    else if (c == 3)
    {
        rot(45.0f, 0.0f, 0.0f);
    }
    else if (c == 5)
    {
        scale(2.0f, 2.0f);
    }
    else if (c == 6)
    {
        scale(0.5f, 0.5f);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Aniket_Style😎");
    ini();
    glutCreateMenu(Menu);
    glutAddMenuEntry("Translate-Right", 1);
    glutAddMenuEntry("Translate-Left", 2);
    glutAddMenuEntry("Rotate-Left", 3);
    glutAddMenuEntry("Rotate-Right", 4);
    glutAddMenuEntry("Scale-Big", 5);
    glutAddMenuEntry("Scale-Small", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}