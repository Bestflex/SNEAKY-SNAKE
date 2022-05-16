#include "Serpent.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>

using namespace std;

Serpent::Serpent()
{
    tab[0].c='@';
    tab[1].c='@'; // caractere de la tête du serpent on utlilise tab[0] et tab[1] pour eviter probleme d'affichage
    taille = 2; //taille initial du serpent (de 2 car on utilise tab[0] et tab[1])
    tab[0].x=2; //coordonnées initiales du serpent
    tab[0].y=2;
    tab[1].x=2; //coordonnées initiales du serpent
    tab[1].y=2;
    direction = 0; // direction serpent 0=droite, 1=haut, 2=gauche, 3=bas
    vie=0; //vie du serpent, booléen car maximum 1 point de vie
}

void Serpent::droite(unsigned int dir) {
	if(dir==0) { tab[0].x = tab[0].x+1; tab[0].y = tab[0].y; } // si la direction est de 0 (droite) on augmente la coordoonée X de la tete du serpent
}

void Serpent::haut(unsigned int dir) {
	if(dir==1) { tab[0].x = tab[0].x; tab[0].y = tab[0].y-1;} // si la direction est de 1 (haut) on diminue la coordoonée Y de la tete du serpent
}

void Serpent::gauche(unsigned int dir) {
	if(dir==2) { tab[0].x = tab[0].x-1; tab[0].y = tab[0].y; } // si la direction est de 2 (gauche) on diminue la coordoonée X de la tete du serpent
}

void Serpent::bas(unsigned int dir) {
	if(dir==3) { tab[0].x = tab[0].x; tab[0].y = tab[0].y+1; } // si la direction est de 3 (bas) on augmente la coordoonée Y de la tete du serpent
}

void Serpent::ajouterCorps()
{
    for(unsigned int i=2; i<=taille; i++) { tab[i].c='o'; } //les caracteres du corps du serpent
}

void Serpent::deplacementCorps()
{
    for(unsigned int i=taille; i>0; i--)
    {
        tab[i].x = tab[i-1].x; //on prend la position X de l'ancienne case occuper par le corps précedent
        tab[i].y = tab[i-1].y; //on prend la position Y de l'ancienne case occuper par le corps précedent
    }
}

bool Serpent :: collisionS() // fonction pour savoir si le serpent se rentre dedans
{
    for(unsigned int i=5; i<taille; i++) //5 car on ne peut pas se rentrer dedans avant une taille de 5
    {
        if(tab[0].x==tab[i].x && tab[0].y==tab[i].y) // si coordoonée tete du serpent1 dans une coordoone de son corps
        {
            return true; // on retourne vrai, il y a collision
        }
    }
    return false; // faux, aucune collision
}

unsigned int Serpent::getTaille()  { return taille; } // on retourne la taille du serpent
void Serpent::setTaille(unsigned int a) { taille=a; } //on modifie la taille du serpent

unsigned int Serpent::getX(unsigned int rang) const { return tab[rang].x; } //on retourne la coordonnée X du serpent en fontion du rang
void Serpent::setX(unsigned int a) { tab[0].x=a; tab[1].x=a; } //on modifie la coordonnée X de la tete du serpent
unsigned int Serpent::getY(unsigned int rang) const { return tab[rang].y; } //on retourne la coordonnée Y du serpent en fontion du rang
void Serpent::setY(unsigned int a) { tab[0].y=a; tab[1].y=a; } //on modifie la coordonnée Y de la tete du serpent
char Serpent::getC(unsigned int rang) const { return tab[rang].c; } // on recupere le caractere du corps de serpent en fonction de son rang (tete (0 et 1): '@', sinon reste du corps: 'o' )

unsigned int Serpent::getDirection() const { return direction; } // on retourne la direction du serpent
void Serpent::setDirection(unsigned int dir) { direction=dir; } //on modifie la direction du serpent

bool Serpent::getVie() const { return vie;} //on retourne le nombres de points de vie du serpent (0: pas de vie, 1: un point de vie)
void Serpent::setVie(bool v) { vie=v;} //on modifie le bool pour les points de vie

void Serpent:: setCorpsX(unsigned int a) { //on deplace les coordonnées X du corps (utiliser dans la procedure respawn dans la class Jeu.cpp)
    for(unsigned int i=2; i<taille; i++)
    {
        tab[i].x=a;
    }
}
void Serpent:: setCorpsY(unsigned int a) { //on deplace les coordonnées Y du corps (utiliser dans la procedure respawn dans la class Jeu.cpp)
    for(unsigned int i=2; i<taille; i++)
    {
        tab[i].y=a;
    }
}

void Serpent::STestRegression()
{
    Serpent s;
    assert(s.taille>0);
    assert(s.taille==2);
    assert(s.direction==0);
    assert(s.vie==0);
    assert((s.tab[0].x>0)&&(s.tab[0].x<30));
    assert((s.tab[0].y>0)&&(s.tab[0].y<10));
    assert(s.tab[0].x==2);
    assert(s.tab[0].y==2);
    s.droite(0);
    assert(s.tab[0].x==3);
    assert(s.tab[0].y==2);
    s.bas(3);
    assert(s.tab[0].x==3);
    assert(s.tab[0].y==3);
    s.gauche(2);
    assert(s.tab[0].x==2);
    assert(s.tab[0].y==3);
    s.haut(1);
    assert(s.tab[0].x==2);
    assert(s.tab[0].y==2);
}
