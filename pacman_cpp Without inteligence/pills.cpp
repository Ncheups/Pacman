#include <GL/gl.h>
#include <GL/glut.h>
#include "pills.h"
#include <stdio.h>

int pills [28][31];

void initPills()
{
    for(int x =0;x<COLUMNS;x++)
    {
        for(int y=0;y<ROWS;y++)
        {
           switch(getState(x,y))
           {
            case 5: pills[x][y] = 1; break;

            default : pills[x][y] = 0; break;
           }
        }
    }
}

void refreshPills()
{
    for(int x =0;x<COLUMNS;x++)
    {
        for(int y=0;y<ROWS;y++)
        {
           switch(pills[x][y])
           {
            case 1: drawComponent(x,y,Pills);

            default : break;
           }
        }
    }
}

bool isPillsEaten(int i, int j)
{
    if(pills[i][j]==1){pills[i][j]=0;return true;}
}

