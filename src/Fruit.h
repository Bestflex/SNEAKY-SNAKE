#ifndef _FRUIT_H
#define _FRUIT_H

#include "Terrain.h"
#include "Serpent.h"
#include "Serpent2.h"
#include "Extra.h"

class Fruit{

private:
    char f; // type de fruit
    unsigned int x,y; // position du fruit

public:
    Fruit(); // Constructeur par default

    void roleFruit(Serpent & s, Terrain & t, Extra & e); // Determine l'effet de chaque fruit sur le Serpent 1
    void roleFruit2(Serpent2 & s2, Terrain & t, Extra & e); // Determine l'effet de chaque fruit sur le Serpent 2
    void changerFruit( Terrain & t); // Permet de tirer un nouveau fruit aleatoirement
    void pomme(Terrain & t); // Permet de remmetre une pomme
    unsigned int getX() const; // Recupere le parametre prive x
    unsigned int getY() const; // Recupere le parametre prive y
    char getCharF() const; // Recupere le parametre prive f

};

#endif
