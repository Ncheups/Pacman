#include <GL/gl.h>
#include <GL/glut.h>
#include "pacman.h"


    Pacman::Pacman(int x,int y)
    {
        pacmanX = x;
        pacmanY =  y;
        currentDir = NONE;
        dirStore = NONE;
        contactWall = false;
    }

    void Pacman::draw()
    {
        glPushMatrix();
        drawComponent(pacmanX,pacmanY,thePacman);
        glPopMatrix();
    }

    void Pacman::move()
    {
        switch(currentDir)
        {
            case LEFT:
                pacmanX -= 1;
                pacmanY = pacmanY;
                break;
            case UP:
                pacmanX = pacmanX;
                pacmanY += 1;
                break;
            case RIGHT:
                pacmanX += 1;
                pacmanY = pacmanY;
                break;
            case DOWN:
                pacmanX = pacmanX;
                pacmanY -= 1;
                break;
            case NONE:
                pacmanX = pacmanX;
                pacmanY = pacmanY;
                break;
        }
    }

    bool Pacman::isPortal()
    {
        if(getState(pacmanX,pacmanY) == 4)
        {
                if(pacmanX == 0 && pacmanY == 16){return true;}
                if(pacmanX == 27 && pacmanY == 16){return true;}
        }
    return false;
    }

    bool Pacman::isWall(direction test)
    {
        switch(test)
        {
            case LEFT:
                if(getState(pacmanX-1,pacmanY) == 0 || getState(pacmanX-1,pacmanY) == 3)
                {return true;}else{return false;}
                break;
            case UP:
                if(getState(pacmanX,pacmanY+1) == 0 || getState(pacmanX,pacmanY+1) == 3)
                {return true;}else{return false;}
                break;
            case RIGHT:
                if(getState(pacmanX+1,pacmanY) == 0 || getState(pacmanX+1,pacmanY) == 3)
                {return true;}else{return false;}
                break;
            case DOWN:
                if(getState(pacmanX,pacmanY-1) == 0 || getState(pacmanX,pacmanY-1) == 3)
                {return true;}else{return false;}
                break;
            default: return true; break;
        }
    }

    void Pacman::info()
    {
        if(isWall(dirStore) == true){printf("contactwall\n");}else{printf("non contactwall\n");}
        printf("currentdir %d\n",currentDir);
        printf("dirStore %d\n",dirStore);
    }

    void Pacman::testDirection()
    {
        if(isWall(dirStore) == false)
        {
            currentDir = dirStore;
        }
        else
        {
            if(isWall(currentDir)== false){currentDir = currentDir;dirStore = currentDir;}
            else{currentDir = NONE;}
        }
    }

    void Pacman::setPos(int x, int y)
    {
        pacmanX = x;
        pacmanY = y;
    }

    void Pacman::switchPortal(int x)
    {
        if(x == 0){pacmanX = 27;};
        if(x == 27){pacmanX = 0;};
    }

    void Pacman::setDirStore(direction pressedDir)
    {
        dirStore = pressedDir;
    }

    direction Pacman::getDirStore()
    {
        return dirStore;
    }

    int Pacman::getPacX()
    {
        return pacmanX;
    }

    int Pacman::getPacY()
    {
        return pacmanY;
    }

    void Pacman::reset()
    {
        pacmanX = 14;
        pacmanY = 13;
        printf("reset\n");
    }
