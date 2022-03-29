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

    void droite(const Terrain & t, unsigned int dir);
    void haut(const Terrain & t, unsigned int dir);
    void gauche(const Terrain & t, unsigned int dir);
    void bas(const Terrain & t, unsigned int dir);

    void ajouterCorps(); // changer la taille du serpent
    void deplacementCorps();

    unsigned int getTaille();
    void setTaille(unsigned int a);
    unsigned int getX() const;
    unsigned int getY() const;
    unsigned int getDirection() const;
    void setDirection(unsigned int dir);
    MorceauS* getTab();


};

#endif // Serpent.h
