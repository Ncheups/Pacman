#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

typedef enum {Wall,Cell,Portal,Gate,thePacman,thePhantom,Fruit} component;

void drawWall(int,int);
void drawCell(int,int);
void drawPortal(int,int);
void drawGate(int,int);
void drawPacman(int,int);
void drawFruit(int,int);
void drawPhantom(int,int);
void drawComponent(int,int,component);


#endif
