#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

int xi, yi, length;
double ET[3][3], ET_Result[3][3];
void Initialize();
void draw_ET();
void mult_3x3();
void translateET();
void scaleET();
void RotateET();

void draw_ET(double ET[3][3])
{
    int i;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
    {
        glVertex2i(ET[i][0], ET[i][1]);
    }
    glEnd();
}

void mult_3x3(double ET[3][3], double temp[3][3])
{

    double sum;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum = sum + ET[i][k] * temp[k][j];
            }
            ET_Result[i][j] = sum;
        }
    }
}

void translateET()
{
    double tx, ty, temp[3][3];

    cout << "Translation" << endl;
    cout << "Enter x translation factor:" << endl;
    cin >> tx;
    cout << "Enter y translation factor:" << endl;
    cin >> ty;

    temp[3][3] = {0};
    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;

    mult_3x3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);
    draw_ET(ET_Result);
}

void scaleET()
{

    double sx, sy, temp[3][3];

    cout << "Scaling" << endl;
    cout << "Enter sx:" << endl;
    cin >> sx;
    cout << "Enter sy:" << endl;
    cin >> sy;

    temp[3][3] = {0};
    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;

    mult_3x3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);

    draw_ET(ET_Result);
}

void RotateET()
{
    double rx, ry, angle, temp[3][3];

    cout << "Rotation" << endl;
    cout << "Enter Arbitrary Points" << endl;
    cin >> rx >> ry;

    cout << "Enter rotation angle" << endl;
    cin >> angle;

    temp[3][3] = {0};
    temp[0][0] = cos(angle);
    temp[0][1] = sin(angle);
    temp[1][0] = -sin(angle);
    temp[1][1] = cos(angle);
    temp[2][2] = 1;
    temp[3][0] = (-(rx * cos(angle)) + (ry * sin(angle)) + rx);
    temp[3][1] = (-(rx * sin(angle)) - (ry * cos(angle)) + ry);
    temp[3][3] = 1;

    mult_3x3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);
    draw_ET(ET_Result);
}

void display()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(-320, 320, -240, 240);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-320, 0);
    glVertex2d(320, 0);
    glVertex2d(0, -240);
    glVertex2d(0, 240);

    glFlush();
}

void Menu(int item)
{
    cout << "MENU" << endl;
    cout << "Tranlatiom" << endl;
    cout << "Scaling" << endl;
    cout << "Rotation" << endl;

    switch (item)
    {
    case 1:
        translateET();
        break;

    case 2:
        scaleET();
        break;

    case 3:
        RotateET();
        break;

    case 4:
        exit(0);
    }
}

int main(int argc, char **argv)
{
    cout << "Enter x co-ordinate of base point" << endl;
    cin >> xi;
    cout << "Enter y co-ordinate of base point" << endl;
    cin >> yi;
    cout << "Enter length of each side" << endl;
    cin >> length;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ET[3][3] = 1;
        }
    }

    ET[0][0] = xi;
    ET[0][1] = yi;
    ET[1][0] = xi + length;
    ET[1][1] = yi;
    ET[2][0] = length / 2 + xi;
    ET[2][1] = (sqrt(3) / 2 * length) + yi;

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2-D Transformations");
    glutDisplayFunc(display);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Tranlation", 1);
    glutAddMenuEntry("2.Scaling", 2);
    glutAddMenuEntry("3.Rotation", 3);
    glutAddMenuEntry("4.EXIT", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return 0;
}
