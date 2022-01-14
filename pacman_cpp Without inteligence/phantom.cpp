#include <GL/gl.h>
#include <GL/glut.h>
#include "phantom.h"

    Phantom::Phantom(int x,int y,int n)
    {
        phantomX = x;
        phantomY =  y;
        name = n;
        bool contactWall;
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

    void Phantom::move()
    {
        dirRefresh();
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

    void Phantom::dirRefresh()
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

    bool Phantom::isContact(int pacX, int pacY)
    {
        if(phantomX == pacX && phantomY == pacY){return true;}else{return false;}
    }

    void Phantom::reset(int name)
    {
        switch(name)
        {
        case 0:
            phantomX = 6;
            phantomY = 25;
            break;
        case 1:
            phantomX = 6;
            phantomY = 10;
            break;
        case 2:
            phantomX = 21;
            phantomY = 25;
            break;
        case 3:
            phantomX = 21;
            phantomY = 10;
            break;
        }
    }
