#ifndef _FRUIT_H
#define _FRUIT_H

#include "Terrain.h"
#include "Serpent.h"


class Fruit{

private:
    char f; // type de fruit
    unsigned int x,y; // position du fruit
    // unsigned int etat; // Pour definir les types de fruit
public:

    Fruit();

    void roleFruit(Serpent & s);
    void changerFruit( Terrain & t);
    unsigned int getX() const;
    unsigned int getY() const;
    char getCharF() const;

};

#endif
