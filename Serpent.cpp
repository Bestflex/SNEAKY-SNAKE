#include "Serpent.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Serpent::Serpent()
{
    Terrain ter;
    tab[0].c='@';
    taille = 1;
    tab[0].x = ter.getDimX()/2;
    tab[0].y = ter.getDimY()/2 + 5;
    direction = 0; // 0=droite, 1=haut, 2=gauche, 3=bas
}

void Serpent::droite(const Terrain & t, unsigned int dir) {
	if(dir==0) {if(t.estDirectionValide(dir))
        { tab[0].x++; deplacementCorps(); }}
}

void Serpent::haut(const Terrain & t, unsigned int dir) {
	if(dir==1) {if(t.estDirectionValide(dir))
        { tab[0].y--; deplacementCorps(); }}
}

void Serpent::gauche(const Terrain & t, unsigned int dir) {
	if(dir==2) {if(t.estDirectionValide(dir))
        { tab[0].x--; deplacementCorps(); }}
}

void Serpent::bas(const Terrain & t, unsigned int dir) {
	if(dir==3) {if(t.estDirectionValide(dir))
        { tab[0].y++; deplacementCorps(); }}
}

void Serpent::ajouterCorps(unsigned int dir)
{
    if(dir==0) { for(unsigned int i=1;i<taille;i++) { tab[i].x=tab[i-1].x - 1; tab[i].y=tab[i-1].y; tab[i].c='o'; }}
    else if(dir==1) { for(unsigned int i=1;i<taille;i++) { tab[i].x=tab[i-1].x ; tab[i].y=tab[i-1].y -1; tab[i].c='o'; }}
    else if(dir==2) { for(unsigned int i=1;i<taille;i++) { tab[i].x=tab[i-1].x + 1; tab[i].y=tab[i-1].y; tab[i].c='o'; }}
    else if(dir==3) { for(unsigned int i=1;i<taille;i++) { tab[i].x=tab[i-1].x; tab[i].y=tab[i-1].y +1; tab[i].c='o'; }}
}

/*void Serpent::poserCorps(Terrain & t)
{
    for(unsigned int i=0;i<taille;i++)
    {

    }

}*/

void Serpent::deplacementCorps()
{
    for(unsigned int i=1; i<taille; i++)
    {
        tab[i].x = tab[i-1].x;
        tab[i].y = tab[i-1].y;
    }
}

unsigned int Serpent::getTaille()  { return taille; }
void Serpent::setTaille(unsigned int a) { taille=a; }

unsigned int Serpent::getX(unsigned int rang) const { return tab[rang].x; }
unsigned int Serpent::getY(unsigned int rang) const { return tab[rang].y; }
char Serpent::getC(unsigned int rang) const { return tab[rang].c; }

unsigned int Serpent::getDirection() const { return direction; }
void Serpent::setDirection(unsigned int dir) { direction=dir; }

MorceauS* Serpent::getTab() {return tab;}


