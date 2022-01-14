#include <GL/gl.h>
#include <GL/glut.h>
#include "draw.h"

void drawWall(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}

void drawCell(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}

void drawPortal(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(0.3,0.5,0.7);
    glBegin(GL_POLYGON);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}

void drawGate(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(0.2,0.6,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}

void drawPacman(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}

void drawPhantom(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}

void drawPills(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(x+0.35,y+0.35); glVertex2d(x+0.85,y+0.35);
        glVertex2d(x+0.85,y+0.35); glVertex2d(x+0.85,y+0.85);
        glVertex2d(x+0.85,y+0.85); glVertex2d(x+0.35,y+0.85);
        glVertex2d(x+0.35,y+0.85); glVertex2d(x+0.35,y+0.35);
    glEnd();
}

void drawFruit(int x,int y)
{
    glLoadIdentity();
    glLineWidth(1.5);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(x+0.25,y+0.25); glVertex2d(x+0.75,y+0.25);
        glVertex2d(x+0.75,y+0.25); glVertex2d(x+0.75,y+0.75);
        glVertex2d(x+0.75,y+0.75); glVertex2d(x+0.25,y+0.75);
        glVertex2d(x+0.25,y+0.75); glVertex2d(x+0.25,y+0.25);
    glEnd();
}

void drawComponent(int x, int y, component block)
{
    switch(block)
    {
    case Wall: drawWall(x,y);break;
    case Cell: drawCell(x,y);break;
    case Portal: drawPortal(x,y);break;
    case Gate: drawGate(x,y);break;
    case thePacman: drawPacman(x,y);break;
    case Fruit: drawFruit(x,y);break;
    case Pills: drawPills(x,y);break;
    case thePhantom: drawPhantom(x,y);break;
    }
}
