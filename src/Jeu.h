#ifndef _JEU_H
#define _JEU_H

#include "Terrain.h"
#include "Serpent.h"
#include "Serpent2.h"
#include "Fruit.h"
#include "Extra.h"

class Jeu{

private:
    int gagnantVS; //0 =egalite, 1=joueur1, 2=joueur2
    unsigned int panier; // choise entre posser que des pommes ou plusieurs fruits differents
    Terrain t;
    Serpent s;
    Serpent2 s2;
    Fruit f;
    Extra e;

public:
    Jeu();
    Terrain& getTerrain();
    Serpent& getSerpent();
    Serpent2& getSerpent2();
    Fruit& getFruit();
    Extra& getExtra();

    bool actionClavier(const char touche);
    void actionsAutomatiques ();
    void choixFruit(unsigned int x);

    unsigned int collisionSerpentCorps();
    bool collisionTete();
    bool finPartie();
    int getGagnant();
    unsigned int getPanier();
    void setPanier(unsigned int x);

    const Terrain& getConstTerrain() const;
    const Serpent& getConstSerpent() const;
    const Serpent2& getConstSerpent2() const;
    const Fruit& getConstFruit() const;
    const Extra& getConstExtra() const;
};

#endif
