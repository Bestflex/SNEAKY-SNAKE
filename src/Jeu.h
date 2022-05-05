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
    unsigned int panier; // choisit entre poser que des pommes ou plusieurs fruits differents, et permet de savoir quel mode de jeux a été lancer
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
    void choixFruit();
    void terrainSpecial();

    unsigned int collisionSerpentCorps();
    bool collisionTete();
    bool finPartie();
    void messageFin();
    int getGagnant();
    unsigned int getPanier();
    void setPanier(unsigned int x);
    int directionAleaX();
    int directionAleaY();
    void jeuAuto ();


    const Terrain& getConstTerrain() const;
    const Serpent& getConstSerpent() const;
    const Serpent2& getConstSerpent2() const;
    const Fruit& getConstFruit() const;
    const Extra& getConstExtra() const;
};

#endif
