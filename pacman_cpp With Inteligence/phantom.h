#ifndef PHANTOM_H_INCLUDED
#define PHANTOM_H_INCLUDED

#include "pacman.h"

class Phantom
{
public:
    int phantomX;
    int phantomY;
    int name;
    int tick;
    int dirPossible[4] = {false}; // [LEFT;UP;RIGHT;DOWN;count]
    direction currentDir;
    direction dirStore;
    direction ytarget;
    direction xtarget;

public:
    Phantom(int,int,int);
    int getPhantomX();
    int getPhantomY();
    void draw();
    int randDir();
    void move(int,int,int);
    direction setDir(int);
    bool isWall(direction);
    void dirRefresh(int,int,int);
    bool isPortal();
    void switchPortal(int);
    void testPossibleDir();
    void setTarget(int,int);
    bool possibleXTarget();
    bool possibleYTarget();
};

#endif
