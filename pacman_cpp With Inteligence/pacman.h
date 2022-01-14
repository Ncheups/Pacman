#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "maze.h"
#include "draw.h"
#include <stdio.h>

typedef enum {LEFT, UP, RIGHT, DOWN, NONE} direction;

class Pacman
{
public:
    int pacmanX;
    int pacmanY;
    bool contactWall;
    direction currentDir;
    direction dirStore;

public:
    Pacman(int,int);
    void draw();
    void move();
    void setPos(int,int);
    void switchPortal(int);
    void setDirStore(direction);
    void testDirection();
    int getPacX();
    int getPacY();
    direction getDirStore();
    bool isWall(direction);
    bool isPortal();
    direction randDir();
    void info();
};

#endif

