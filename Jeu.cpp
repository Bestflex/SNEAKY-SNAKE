#include "Jeu.h"

Jeu::Jeu () : t(), s(), f() {
	//t.mangeFruit(s.getX(),s.getY());
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
	unsigned int sx = s.getX(0);
	unsigned int sy = s.getY(0);
	unsigned int fx = f.getX();
	unsigned int fy = f.getY();


	if(sx ==fx && sy==fy)
    {
        t.mangeFruit(fx,fy);
        f.roleFruit(s);
        s.ajouterCorps(a);
        f.changerFruit(t);
        return true;
	}
    //s.ajouterCorps();
	return false;
}

const Terrain& Jeu::getConstTerrain () const { return t; }
const Serpent& Jeu::getConstSerpent () const { return s; }
const Fruit& Jeu::getConstFruit () const { return f; }

/*void Jeu::actionsAutomatiques () {
    //s.versFruit(t,s);
    s.bougeAuto(t);
}*/
