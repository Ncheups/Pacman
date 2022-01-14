#include <GL/glut.h>

#include "phantom.h"
#include "draw.h"
#include "maze.h"
#include "pacman.h"
#include "fruit.h"
#include "pills.h"

#include <stdio.h>

bool contact;
int time = 0;

Pacman pacman(14,13);

Phantom phantoms[4] = {
        Phantom(6, 25, 0),
        Phantom(6, 10, 1),
        Phantom(21, 25, 2),
        Phantom(21, 10, 3),
};

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    initFruit();
    initPills();
}


void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    draw_maze();

    isFruitEaten(pacman.getPacX(),pacman.getPacY());
    refreshFruit();

    if(isPillsEaten(pacman.getPacX(),pacman.getPacY()) == true){time = 500;}
    refreshPills();

    pacman.isWall(pacman.getDirStore());
    pacman.testDirection();
    pacman.move();
    if(pacman.isPortal() == true)
    {
     pacman.switchPortal(pacman.getPacX());
    }
    pacman.draw();


    for(int i=0;i<4;i++)
    {
        phantoms[i].draw();
        phantoms[i].move();
        contact = phantoms[i].isContact(pacman.getPacX(),pacman.getPacY());

        if(contact == true && time > 0){phantoms[i].reset(phantoms[i].name);}
        if(contact == true && time == 0){pacman.reset();}

        if(phantoms[i].isPortal() == true)
        {
            phantoms[i].switchPortal(phantoms[i].getPhantomX());
        }
    }
    printf("%d \n",time);
    if(time > 0){time--;}
    glutSwapBuffers();

    //pacman.info();
}

void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLfloat)w,GLfloat(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(100,timer_callback,0);
}

void special(int key, int, int)
{
    switch (key)
    {
        case GLUT_KEY_LEFT: pacman.setDirStore(LEFT);
            break;
        case GLUT_KEY_UP: pacman.setDirStore(UP);
            break;
        case GLUT_KEY_RIGHT: pacman.setDirStore(RIGHT);
            break;
        case GLUT_KEY_DOWN: pacman.setDirStore(DOWN);
            break;
    }
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(512,512);
    glutCreateWindow("PACMAN");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutSpecialFunc(special);
    glutTimerFunc(100,timer_callback,0);
    init();
    glutMainLoop();
    return 0;
}

