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
    direction currentDir;
    direction dirStore;

public:
    Phantom(int,int,int);
    int getPhantomX();
    int getPhantomY();
    void draw();
    int randDir();
    void move();
    direction setDir(int);
    bool isWall(direction);
    void dirRefresh();
    bool isPortal();
    void switchPortal(int);
    bool isContact(int,int);
    void reset(int);
};

#endif
