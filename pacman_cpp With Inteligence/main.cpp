#include <GL/glut.h>

#include "phantom.h"
#include "draw.h"
#include "maze.h"
#include "pacman.h"
#include "fruit.h"

#include <stdio.h>

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
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    draw_maze();

    isEaten(pacman.getPacX(),pacman.getPacY());
    refreshFruit();

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
        phantoms[i].move(pacman.getPacX(),pacman.getPacY(),phantoms[i].name);

        if(phantoms[i].isPortal() == true)
        {
            phantoms[i].switchPortal(phantoms[i].getPhantomX());
        }
    }

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
        default :
            printf("%c = %d", key, key);
    }
}

void vClavier(unsigned char key, int x, int y)
{
	printf(" Touche: %c = %d \n",key,key);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(512,512);
    glutCreateWindow("PACMAN");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutKeyboardFunc(vClavier);
    glutSpecialFunc(special);

    glutTimerFunc(100,timer_callback,0);
    init();
    glutMainLoop();
    return 0;
}

