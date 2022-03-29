#include "Jeu.h"

Jeu::Jeu () : t(), s(), f() {
	t.mangeFruit(s.getX(),s.getY());
}

Terrain& Jeu::getTerrain() {return t;}
Serpent& Jeu::getSerpent() {return s;}
Fruit& Jeu::getFruit() {return f;}

bool Jeu::actionClavier (const char touche) {
	unsigned int a;
	switch(touche) {
		case 'q' :
                a=2;
				s.gauche(t,a);
				break;
		case 'd' :
                a=0;
				s.droite(t,a);
				break;
		case 'z' :
                a=1;
				s.haut(t,a);
				break;
		case 's' :
                a=3;
				s.bas(t,a);
				break;
	}
	unsigned int x = s.getX();
	unsigned int y = s.getY();
	if((t.getXY(x,y)!='#')||(t.getXY(x,y)!='o')||(t.getXY(x,y)!='@')||(t.getXY(x,y)!=' '))
    {
        t.mangeFruit(x,y);
        return true;
	}
	return false;
}

const Terrain& Jeu::getConstTerrain () const { return t; }
const Serpent& Jeu::getConstSerpent () const { return s; }
const Fruit& Jeu::getConstFruit () const { return f; }

/*void Jeu::actionsAutomatiques () {
    //s.versFruit(t,s);
    s.bougeAuto(t);
}*/
