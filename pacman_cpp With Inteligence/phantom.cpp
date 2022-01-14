#include <GL/gl.h>
#include <GL/glut.h>
#include "phantom.h"

    Phantom::Phantom(int x,int y,int n)
    {
        phantomX = x;
        phantomY =  y;
        name = n;

        direction currentDir = NONE;
        direction dirStore = NONE;
        tick = 0;
    }

    void Phantom::draw()
    {
        glPushMatrix();
        drawComponent(phantomX,phantomY,thePhantom);
        glPopMatrix();
    }

    int Phantom::randDir()
    {
        int ran = rand() % 4 + 1;
        return ran;
    }

    direction Phantom::setDir(int c)
    {
        switch(c)
        {
            case 1:
                return UP;
                break;
            case 2:
                return DOWN;
                break;
            case 3:
                return RIGHT;
                break;
            case 4:
                return LEFT;
                break;
            default:
                return NONE;
                break;
        }
    }

    bool Phantom::isWall(direction test)
    {
        switch(test)
        {
            case LEFT:
                if(getState(phantomX-1,phantomY) == 0 || getState(phantomX-1,phantomY) == 3)
                {return true;}else{return false;}
                break;
            case UP:
                if(getState(phantomX,phantomY+1) == 0 || getState(phantomX,phantomY+1) == 3)
                {return true;}else{return false;}
                break;
            case RIGHT:
                if(getState(phantomX+1,phantomY) == 0 || getState(phantomX+1,phantomY) == 3)
                {return true;}else{return false;}
                break;
            case DOWN:
                if(getState(phantomX,phantomY-1) == 0 || getState(phantomX,phantomY-1) == 3)
                {return true;}else{return false;}
                break;
            default: return true; break;
        }
    }

    void Phantom::move(int pacX,int pacY,int name)
    {
        dirRefresh(pacX,pacY,name);
        switch(currentDir)
        {
            case LEFT:
                phantomX -= 1;
                phantomY = phantomY;
                break;
            case UP:
                phantomX = phantomX;
                phantomY += 1;
                break;
            case RIGHT:
                phantomX += 1;
                phantomY = phantomY;
                break;
            case DOWN:
                phantomX = phantomX;
                phantomY -= 1;
                break;
            case NONE:
                phantomX = phantomX;
                phantomY = phantomY;
                break;
        }
    }

    void Phantom::dirRefresh(int pacX,int pacY, int name)
    {
        currentDir = NONE;
        if(name == 1)
        {
            setTarget(pacX,pacY);
            testPossibleDir();


                if(isWall(currentDir) || possibleXTarget() ||possibleYTarget())
                {
                    dirStore = NONE;
                    if(phantomX != pacX)
                    {
                        if(xtarget == RIGHT && dirPossible[2] == 1){dirStore = RIGHT;}
                        if(xtarget == LEFT && dirPossible[0] == 1){dirStore = LEFT;}
                    }
                    if(phantomY != pacY)
                    {
                        if(ytarget == UP && dirPossible[1] == 1){dirStore = UP;}
                        if(ytarget == DOWN && dirPossible[3] == 1){dirStore = DOWN;}
                    }
                }
                    currentDir = dirStore;

            if(tick >= 11){tick = 0;}else{tick++;}
        }

        if(name == 2)
        {
            if(tick % 5 == 0 || isWall(currentDir) == true)
            {
                do
                {
                    dirStore = setDir(randDir());
                }while(isWall(dirStore) == true);
                currentDir = dirStore;
            }
            if(tick >= 11){tick = 0;}else{tick++;}
        }

        if(name == 3)
        {
            if(isWall(currentDir) == true)
            {
                do
                {
                    dirStore = setDir(randDir());
                }while(isWall(dirStore) == true);
                currentDir = dirStore;
            }
        }

        if(name == 0)
        {
            if(isWall(currentDir) == true)
            {
                do
                {
                    dirStore = setDir(randDir());
                }while(isWall(dirStore) == true);
                currentDir = dirStore;
            }
        }

    }


    bool Phantom::isPortal()
    {
        if(getState(phantomX,phantomY) == 4)
        {
                if(phantomX == 0 && phantomY == 16){return true;}
                if(phantomX == 27 && phantomY == 16){return true;}
        }
    return false;
    }

    void Phantom::switchPortal(int x)
    {
        if(x == 0){phantomX = 27;};
        if(x == 27){phantomX = 0;};
    }

    int Phantom::getPhantomX()
    {
        return phantomX;
    }

    int Phantom::getPhantomY()
    {
        return phantomY;
    }

    void Phantom::testPossibleDir()
    {
        dirPossible[4] = 0;
        if(isWall(UP) == true){dirPossible[1] = 0;}else{dirPossible[1] = 1;dirPossible[4] = dirPossible[4]+1;}
        if(isWall(DOWN) == true){dirPossible[3] = 0;}else{dirPossible[3] = 1;dirPossible[4] = dirPossible[4]+1;}
        if(isWall(LEFT) == true){dirPossible[0] = 0;}else{dirPossible[0] = 1;dirPossible[4] = dirPossible[4]+1;}
        if(isWall(RIGHT) == true){dirPossible[2] = 0;}else{dirPossible[2] = 1;dirPossible[4] = dirPossible[4]+1;}
    }

    void Phantom::setTarget(int pacX, int pacY)
    {
        if(phantomX > pacX){xtarget = LEFT;}else{xtarget = RIGHT;}
        if(phantomY > pacY){ytarget = DOWN;}else{ytarget = UP;}
    }

    bool Phantom::possibleXTarget()
    {
        switch(xtarget)
        {
        case RIGHT:
            if(dirPossible[2] == 1){return true;}
            break;
        case LEFT:
            if(dirPossible[0] == 1){return true;}
            break;
        case NONE:
            return false;
            break;
        }
    }

    bool Phantom::possibleYTarget()
    {
        switch(xtarget)
        {
        case UP:
            if(dirPossible[1] == 1){return true;}
            break;
        case DOWN:
            if(dirPossible[3] == 1){return true;}
            break;
        case NONE:
            return false;
            break;
        }
    }
