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
    Terrain& getTerrain();
    Serpent& getSerpent();
    Fruit& getFruit();

    bool actionClavier(const char touche);
    void actionsAutomatiques ();

    const Terrain& getConstTerrain() const;
    const Serpent& getConstSerpent() const;
    const Fruit& getConstFruit() const;
};

#endif
