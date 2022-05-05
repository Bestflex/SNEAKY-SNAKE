#ifndef _SERPENT2_H
#define _SERPENT2_H


#include "Terrain.h"


const int MAX2 = 200;

struct MorceauS2
{
    char c;
    unsigned int x,y; //position du serpent2
};

class Serpent2{
private:

    MorceauS2 tab[MAX2];
    unsigned int taille;
    unsigned int direction;

public :

    Serpent2();
    void droite(const Terrain & t, unsigned int dir);
    void haut(const Terrain & t, unsigned int dir);
    void gauche(const Terrain & t, unsigned int dir);
    void bas(const Terrain & t, unsigned int dir);

    void ajouterCorps();
    void deplacementCorps();
    void bougeAuto(const Terrain & t);

    bool collisionS();

    unsigned int getTaille();
    void setTaille(unsigned int a);
    unsigned int getX(unsigned int rang) const;
    void setX(unsigned int a);
    unsigned int getY(unsigned int rang) const;
    void setY(unsigned int a);
    char getC(unsigned int rang) const;
    unsigned int getDirection() const;
    void setDirection(unsigned int dir);

};

#endif // Serpent2.h
