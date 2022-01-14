#include <GL/gl.h>
#include <GL/glut.h>
#include "fruit.h"
#include <stdio.h>

int fruit [28][31];

void initFruit()
{
    for(int x =0;x<COLUMNS;x++)
    {
        for(int y=0;y<ROWS;y++)
        {
           switch(getState(x,y))
           {
            case 1: fruit[x][y] = 1; break;
            default : fruit[x][y] = 0; break;
           }
        }
    }
}

void refreshFruit()
{
    for(int x =0;x<COLUMNS;x++)
    {
        for(int y=0;y<ROWS;y++)
        {
           switch(fruit[x][y])
           {
            case 1: drawComponent(x,y,Fruit);
            default : break;
           }
        }
    }
}

void isEaten(int i, int j)
{
    if(fruit[i][j]==1){fruit[i][j]=0;}
}
