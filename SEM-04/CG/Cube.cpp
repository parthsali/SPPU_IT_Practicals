#include <GL/freeglut.h>

// Cube vertices
GLfloat vertices[][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};

// Cube edges
GLint edges[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

// Cube colors
GLfloat colors[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}, {0.5, 0.5, 0.5}, {0, 1, 0.5}, {0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}};

// Rotation angle
GLfloat angle = 0.0f;

void drawCube()
{
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f); // Move the cube away from the
    // camera
    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotate about vertical axis

    glBegin(GL_LINES);
    for (int i = 0; i < 12; ++i)
    {
        glColor3fv(colors[i % 12]);
        glVertex3fv(vertices[edges[i][0]]);
        glVertex3fv(vertices[edges[i][1]]);
    }
    glEnd();

    glutSwapBuffers();
}

void update(int _)
{
    angle += 1.0f; // Increment rotation angle
    if (angle > 360)
        angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cube Rotation");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 100);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawCube);
    glutTimerFunc(1000 / 60, update, 0);

    glutMainLoop();
    return 0;
}