#include "Jeu.h"

Jeu::Jeu () : ter(), Serpent(), fruit() {
	ter.mangePastille(pac.getX(),pac.getY());
}

Terrain & Jeu::getTerrain & () {return ter;}
Serpent & Jeu::getSerpent & () {return ser;}
