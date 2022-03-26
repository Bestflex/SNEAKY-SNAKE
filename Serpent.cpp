#include "Terrain.h"
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
    tab[0].y = ter.getDimY()/2;
    direction = 0; // 0=droite, 1=haut, 2=gauche, 3=bas
}

void Serpent::deplacement(const Terrain & t, unsigned int dir)
{
    if(dir==0) {if(t.estDirectionValide(dir)) { tab[0].x++; }
    else if(dir==1) {if(t.estDirectionValide(dir)) { tab[0].y++; }
    else if(dir==2) {if(t.estDirectionValide(dir)) { tab[0].x--; }
    else if(dir==3) {if(t.estDirectionValide(dir)) { tab[0].y--; }
}

void Serpent::ajouterCorps()
{
    for(unsigned int i=1;i<taille;i++) { tab[i].c='o'; }
}

unsigned int Serpent::getTaille()  { return & taille; }

unsigned int Serpent::setTaille(unsigned int a) { taille=a; }

unsigned int Serpent::getX() const { return tab[MAX].x; }

unsigned int Serpent::getY() const { return tab[MAX].y; }

unsigned int Serpent::getDirection() const { return direction; }

MorceauS Serpent::getTab() {return & tab[MAX];}


