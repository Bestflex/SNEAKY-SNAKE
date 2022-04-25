#include "Jeu.h"
#include <iostream>
#include <time.h>
using namespace std;
Jeu::Jeu() : t(), s(), s2(), f(), e() { gagnantVS =0; /*egalite*/ } // Constructeur par default

Terrain& Jeu::getTerrain() {return t;} // Renvoie les donnees du Terrain
Serpent& Jeu::getSerpent() {return s;} // Renvoie les donnees du Serpent
Serpent2& Jeu::getSerpent2() {return s2;} // Renvoie les donnees du Serpent2
Fruit& Jeu::getFruit() {return f;} // Renvoie les donnees du Fruit
Extra& Jeu::getExtra() {return e;} // Renvoie les donnees du Fruit

bool Jeu::actionClavier (const char touche) { // Definit les actions des touches
	unsigned int a =s.getDirection(); //on recupere la direction du serpent 1
	unsigned int a2=s2.getDirection(); //on recupere la direction du serpent 2
	switch(touche)
	{
		case 'q' : if(a!=0)a=2; s.setDirection(a); break; //si on va droite on ne peut pas aller a gauche
		case 'd' : if(a!=2)a=0; s.setDirection(a); break;
		case 'z' : if(a!=3)a=1; s.setDirection(a); break;
		case 's' : if(a!=1)a=3; s.setDirection(a); break;
        case 'k' : if(a2!=0)a2=2; s2.setDirection(a2); break;
		case 'm' : if(a2!=2)a2=0; s2.setDirection(a2); break;
		case 'o' : if(a2!=3)a2=1; s2.setDirection(a2); break;
		case 'l' : if(a2!=1)a2=3; s2.setDirection(a2); break;
	} //0=droite, 1=haut, 2=gauche, 3=bas
	return false;
}


void Jeu::choixFruit(unsigned int x)
{
    unsigned int sx0 = s.getX(0);
    unsigned int sy0 = s.getY(0);

    unsigned int s2x = s2.getX(0);
    unsigned int s2y = s2.getY(0);

    unsigned int fx = f.getX();
    unsigned int fy = f.getY();

    if(x==0)
    {
        if(sx0 ==fx && sy0==fy)
        {
            t.mangeFruit(fx,fy);
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.pomme(t);
        }
    }
    else if(x==1)
    {
        if(sx0 ==fx && sy0==fy)
        {
            t.mangeFruit(fx,fy);
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.changerFruit(t);
        }
        if(s2x ==fx && s2y==fy)
        {
            t.mangeFruit(fx,fy);
            s2.ajouterCorps();
            f.roleFruit2(s2,t,e);
            f.changerFruit(t);
        }
    }
}

unsigned int Jeu::collisionSerpentCorps() //test quel serpent rentre dans le corps de l'autre
{
    unsigned int joueur;

    for(unsigned int i=2; i<s2.getTaille();i++)
    {
        if(s.getX(0)==s2.getX(i) && s.getY(0)==s2.getY(i)) { joueur=1; }
        //else { return false; }
    }
    for(unsigned int j=2; j<s.getTaille();j++)
    {
        if(s2.getX(0)==s.getX(j) && s2.getY(0)==s.getY(j)) { joueur=2; }
    }

    return joueur;
}

bool Jeu:: collisionTete() //teste si les tetes des serpents se percutent
{
    if(s.getX(0)==s2.getX(0) && s.getY(0)==s2.getY(0)){return true; }
    return false;
}

bool Jeu:: finPartie()
{
    unsigned int sx0 = s.getX(0); //x de la tete du serpent 1
	unsigned int sy0 = s.getY(0); //y de la tete du serpent 2

	unsigned int s2x0 = s2.getX(0); //x serpent2
	unsigned int s2y0 = s2.getY(0); //y serpent2

	if(s.getTaille()<2) { gagnantVS=2; return false; }
	if(s2.getTaille()<2) { gagnantVS=1; return false; }

	if(s.collisionS()==true) // si serpent1 se rentre dedans
    {
        gagnantVS=2;
        return false;
    }

    if(s2.collisionS()==true) // si serpent2 se rentre dedans
    {
        gagnantVS=2;
        return false;
    }

    if(t.collisionT(sx0, sy0) == true) // si serpent1 rentre dans un mur
                {
                    gagnantVS=2;
                    return false;
                }

    if(t.collisionT(s2x0, s2y0) == true) // si serpent2 rentre dans un mur
                {
                    gagnantVS=1;
                    return false;
                }

    if(collisionSerpentCorps()==1){
        gagnantVS=2;
        return false;
    }
    else if(collisionSerpentCorps()==2) {
        gagnantVS=1;
        return false;
    }

    if(collisionTete()){return false;}

    return true;
}

int Jeu::getGagnant(){ return gagnantVS; }
unsigned int Jeu::getPanier() { return panier; }
void Jeu::setPanier(unsigned int x) { panier=x; }

const Terrain& Jeu::getConstTerrain () const { return t; }
const Serpent& Jeu::getConstSerpent () const { return s; }
const Serpent2& Jeu::getConstSerpent2 () const { return s2; }
const Fruit& Jeu::getConstFruit () const { return f; }
const Extra& Jeu::getConstExtra () const { return e; }

//void Jeu::actionsAutomatiques () { s.bougeAuto(s.getDirection(),t); }
