#include "Serpent2.h"

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>

using namespace std;

Serpent2::Serpent2()
{
    tab[0].c='X';
    tab[1].c='X';
    taille = 2;
    direction = 2; // 0=droite, 1=haut, 2=gauche, 3=bas
    Terrain ter;
    tab[0].x = ter.getDimX()-3;
    tab[0].y = ter.getDimY()-3;
}

void Serpent2::droite(const Terrain & t, unsigned int dir) {
	if(dir==0) { tab[0].x = tab[0].x+1; tab[0].y = tab[0].y; }
}

void Serpent2::haut(const Terrain & t, unsigned int dir) {
	if(dir==1) { tab[0].x = tab[0].x; tab[0].y = tab[0].y-1;}
}

void Serpent2::gauche(const Terrain & t, unsigned int dir) {
	if(dir==2)  { tab[0].x = tab[0].x-1; tab[0].y = tab[0].y; }
}

void Serpent2::bas(const Terrain & t, unsigned int dir) {
	if(dir==3)  { tab[0].x = tab[0].x; tab[0].y = tab[0].y+1; }
}

void Serpent2::ajouterCorps()
{
    for(unsigned int i=2; i<=taille; i++) { tab[i].c='+'; }
}

/*void Serpent::poserCorps(Terrain & t)*/

void Serpent2::deplacementCorps()
{
    for(unsigned int i=taille; i>0; i--)
    {
        tab[i].x = tab[i-1].x;
        tab[i].y = tab[i-1].y;
    }
}

bool Serpent2::collisionS()
{

    unsigned int sx;
    unsigned int sy;
    for(unsigned int i=5; i<taille; i++) //5 car on ne peut pas se rentrer dedans avant  une taille de 5
    {
        sx=tab[i].x;
        sy=tab[i].y;
        if(tab[0].x==sx && tab[0].y==sy) // si coordoonée tete du serpent2 dans coordoone de son corps
        {
            return true;
        }
    }
    return false;
}

void Serpent2::bougeAuto (const Terrain & t) {
    int dx [4] = { 1, 0, -1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;
    xtmp = tab[0].x + dx[direction];
    ytmp = tab[0].y + dy[direction];
    if (t.collisionT(xtmp,ytmp)==false &&collisionS()==false) {
        tab[0].x = xtmp;
        tab[0].y = ytmp;
        direction = rand()%4;
    }
    else direction = rand()%4;
}


unsigned int Serpent2::getTaille()  { return taille; }
void Serpent2::setTaille(unsigned int a) { taille=a; }

unsigned int Serpent2::getX(unsigned int rang) const { return tab[rang].x; }
void Serpent2::setX(unsigned int a) { tab[1].x=a; }
unsigned int Serpent2::getY(unsigned int rang) const { return tab[rang].y; }
void Serpent2::setY(unsigned int a) { tab[1].y=a; }
char Serpent2::getC(unsigned int rang) const { return tab[rang].c; }

unsigned int Serpent2::getDirection() const { return direction; }
void Serpent2::setDirection(unsigned int dir) { direction=dir; }




