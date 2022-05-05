#include "Jeu.h"
#include <iostream>
#include <time.h>
using namespace std;
Jeu::Jeu() : t(), s(), s2(), f(), e() { gagnantVS =0; /*egalite*/ panier=0; } // Constructeur par default

Terrain& Jeu::getTerrain() {return t;} // Renvoie les donnees du Terrain
Serpent& Jeu::getSerpent() { return s;} // Renvoie les donnees du Serpent
Serpent2& Jeu::getSerpent2() {return s2;} // Renvoie les donnees du Serpent2
Fruit& Jeu::getFruit() {return f;} // Renvoie les donnees du Fruit
Extra& Jeu::getExtra() {return e;} // Renvoie les donnees du Fruit

bool Jeu::actionClavier (const char touche) { // Definit les actions des touches
	unsigned int a =s.getDirection(); //on recupere la direction du serpent 1
	unsigned int a2=s2.getDirection(); //on recupere la direction du serpent 2
	switch(touche)
	{
		case 'q' : if(a!=0)a=2; s.setDirection(a); break; //si on se depalce vers la droite on ne peut pas se deplacer vers la gauche
		case 'd' : if(a!=2)a=0; s.setDirection(a); break;
		case 'z' : if(a!=3)a=1; s.setDirection(a); break;//si on se deplace vers le bas on ne peut pas aller vers le haut (a!3=bas)
		case 's' : if(a!=1)a=3; s.setDirection(a); break;
        case 'k' : if(a2!=0)a2=2; s2.setDirection(a2); break;
        case 'm' : if(a2!=2)a2=0; s2.setDirection(a2); break;
        case 'o' : if(a2!=3)a2=1; s2.setDirection(a2); break;
        case 'l' : if(a2!=1)a2=3; s2.setDirection(a2); break;
	} //0=droite, 1=haut, 2=gauche, 3=bas
	return false;
}


void Jeu::choixFruit()
{
    unsigned int sx0 = s.getX(0);
    unsigned int sy0 = s.getY(0);

    unsigned int s2x = s2.getX(0);
    unsigned int s2y = s2.getY(0);

    unsigned int fx = f.getX();
    unsigned int fy = f.getY();

    if(panier==0) //solo
    {
        if(sx0 ==fx && sy0==fy)
        {
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.pomme(t);
        }
    }
    else if(panier==1) //solo mode arcarde
    {
        if(sx0 ==fx && sy0==fy)
        {
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.changerFruit(t);
        }
    }
    else if(panier==2 || panier==3) //1 contre 1
    {

          if(sx0 ==fx && sy0==fy)
        {
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.changerFruit(t);
        }

          if(s2x ==fx && s2y==fy)
        {
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
    if(panier==2) //seulement si on joue en 1 contre 1
    {
        if(s.getX(0)==s2.getX(0) && s.getY(0)==s2.getY(0)){return true; }
    }
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
        gagnantVS=1;
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

void Jeu::messageFin()
{
    if(panier==0 || panier==1) //il y a un seul serpent
    {
        cout <<"dommage vous avez perdu, votre score est de : "  << e.getScore1() << endl;
    }
    else if(panier==2 || panier==3) // il y a 2 serpent sur le terrain
    {
        if(gagnantVS==1 || ((gagnantVS==0)&&(e.getScore1()>e.getScore2()))) { cout << "Bravo, vous avez gagne Serpent1" << endl; }//soit serpent2 a perdu, soit egalite mais score du serpent 1 > score serpent2
        else if(gagnantVS==2 || ((gagnantVS==0)&&(e.getScore1()<e.getScore2()))) { cout << "Bravo Serpent2, vous avez gagne" << endl; }
        else if((gagnantVS==0)&&(e.getScore1()==e.getScore2())) cout <<"egalite" <<endl; //pour une egalite il faut que le serpent1 et le serpent2 se rentre dans la tete + meme score
        cout << "le score du serpent1 est de: " << e.getScore1() << endl;
        cout << "le score du serpent2 est de: " << e.getScore2() << endl;
    }

}

void Jeu::terrainSpecial()
{
    if(t.collisionTSpecial(s.getX(0),s.getY(0))){t.setChoix(rand()%3), s.setX(2),s.setY(2),s.setDirection(0);} //si on touche un mur du terrain on change de nouveau de terrain
    if(t.collisionTeleporteur1(s.getX(0),s.getY(0))){s.setX(21),s.setY(6),s.setDirection(2);}
    if(t.collisionTeleporteur2(s.getX(0),s.getY(0))){s.setX(26),s.setY(8),s.setDirection(2);}
}

void Jeu::jeuAuto () { // procedure pour le fonctionnement de l'ia

        srand(time(NULL));
        int directionAleaX=rand()%5;
        int directionAleaY=rand()%5;
        if (directionAleaX ==0 ||directionAleaX ==4) {directionAleaX=2;} //1 chance sur deux pour la direction sur axe X
        else {directionAleaX=1;}
        if (directionAleaX ==0 ||directionAleaX ==4) {directionAleaX=1;} //1 chance sur deux pour la direction sur axe Y
        else {directionAleaY=3;}

        int dx = f.getX()-s2.getX(0); //savoir la position du fruit en fonction de la position du serpent2
        int dy = f.getY()-s2.getY(0);
        if (dx>0) dx=0; //le fruit est sur la droite du serpent
        if (dx<0) dx=2; //le fruit est sur la gauche du serpent
        if (dy>0) dy=3; //le fruit est en bas du serpent
        if (dy<0) dy=1; //le fruit est en haut du serpent
        if (dx==0) dx=dy;
        if(dy==0) dy=dx;

        if(s2.getDirection()==0)
        {
            if((t.collisionT(s2.getX(0)+1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)+1)==false && t.collisionT(s2.getX(0),s2.getY(0)-1)==false)) {s2.setDirection(directionAleaY);} //si mur vers la droite mais pas en haut et en bas, met une direction aleatoire
            else if(t.collisionT(s2.getX(0)+1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)==false) {s2.setDirection(1);} //si mur sur la droite mais pas vers le haut, va en haut
            else if(t.collisionT(s2.getX(0)+1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)) {s2.setDirection(3);}//si mur sur la droite mais pas sur vers le bas, va en bas
            else if(dx!=2 ) {s2.setDirection(dx);} //dx!=2 pour empecher l'ia de faire demi tour
        }
        if(s2.getDirection()==1)
        {
           if((t.collisionT(s2.getX(0),s2.getY(0)-1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false && t.collisionT(s2.getX(0)-1,s2.getY(0))==false)) {s2.setDirection(directionAleaX);}//si mur vers le haut mais pas sur la droite et sur la gauche, met une direction aleatoire
           else if(t.collisionT(s2.getX(0),s2.getY(0)-1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false) {s2.setDirection(0);}//si mur vers le haut mais pas vers la doite, va sur la droite
           else if(t.collisionT(s2.getX(0),s2.getY(0)-1) && t.collisionT(s2.getX(0)+1,s2.getY(0))) {s2.setDirection(2);}//si mur vers le haut mais pas vers la doite, va sur la droite
           else if(dx!=3 ) {s2.setDirection(dy);}
        }
        if(s2.getDirection()==2)
        {
           if((t.collisionT(s2.getX(0)-1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)+1)==false && t.collisionT(s2.getX(0),s2.getY(0)-1)==false)) {s2.setDirection(directionAleaY);}
           else if(t.collisionT(s2.getX(0)-1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)==false) {s2.setDirection(1);}
           else if(t.collisionT(s2.getX(0)-1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)) {s2.setDirection(3);}
          else if(dx!=0){s2.setDirection(dx);}
        }
          if(s2.getDirection()==3)
        {
           if((t.collisionT(s2.getX(0),s2.getY(0)+1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false && t.collisionT(s2.getX(0)-1,s2.getY(0))==false)) {s2.setDirection(directionAleaX);}
           else if(t.collisionT(s2.getX(0),s2.getY(0)+1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false) {s2.setDirection(0);}
           else if(t.collisionT(s2.getX(0),s2.getY(0)+1) && t.collisionT(s2.getX(0)+1,s2.getY(0))) {s2.setDirection(2);}
          else if(dx!=1){s2.setDirection(dy);}
        }

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
