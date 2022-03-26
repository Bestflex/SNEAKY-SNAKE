#ifndef _JEU_H
#define _JEU_H

#include "Terrain.h"
#include "Serpent.h"
#include "Fruit.h"

class Jeu{

private:
    Terrain t;
    Serpent s;
    Fruit f;

public:
    Jeu();

    getTerrain& ();
    getSerpent& ();

    void actionClavier(const char touche);

};
