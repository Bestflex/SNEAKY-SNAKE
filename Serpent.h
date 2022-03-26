#ifndef _SERPENT_H
#define _SERPENT_H

#include "Terrain.h"

const int MAX = 200;

struct MorceauS
{
    char c;
    unsigned int x,y; //position du serpent
};

class Serpent{
private:

    MorceauS tab[MAX];
    unsigned int taille;
    unsigned int direction;

public :

    Serpent();

    void deplacement(const Terrain & t, unsigned int dir); // deplacement du serpent
    void ajouterCorps(); // changer la taille du serpent

    unsigned int getTaille();
    unsigned int setTaille(unsigned int a);
    unsigned int getX() const;
    unsigned int getY() const;
    unsigned int getDirection() const;
    MorceauS getTab();


};

#endif // Serpent.h
