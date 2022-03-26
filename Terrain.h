#ifndef _TERRAIN_H
#define _TERRAIN_H

#include "Terrain.h"
#include "Serpent.h"
#include "Fruit.h"

class Terrain{

private:
    unsigned int dimx;
	unsigned int dimy;
	char ter[100][100];

public:
    Terrain();

    bool collision(Serpent & s); // test collision avec mur et corps
    void mangeFruit(Serpent & s);
    void poserFruit(const Fruit & f);
    bool estDirectionValide(unsigned int direction) const;

    char getXY(unsigned int x,unsigned int y); //renvoie le type d'objet a une position x,y;
    unsigned int getDimX() const;
    unsigned int getDimY() const;


};

#endif
