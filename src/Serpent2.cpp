#include "Serpent2.h"

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>

using namespace std;

Serpent2::Serpent2()
{
    tab[0].c='X'; // caractere de la tête du serpent on utlilise tab[0] et tab[1] pour eviter probleme d'affichage
    tab[1].c='X';
    taille = 2; // caractere de la tête du serpent on utlilise tab[0] et tab[1] pour eviter probleme d'affichage
    direction = 2; // direction serpent 0=droite, 1=haut, 2=gauche, 3=bas
    Terrain ter; // on recupere la class Terrain
    tab[0].x = ter.getDimX()-3; //coordonnées initiales du serpent, on utlise la class Terrain pour placer le serpent
    tab[0].y = ter.getDimY()-3;
    vie=0; //vie du serpent, booléen car maximum 1 point de vie
}

void Serpent2::droite(const Terrain & t, unsigned int dir) {
	if(dir==0) { tab[0].x = tab[0].x+1; tab[0].y = tab[0].y; } // si la direction est de 0 (droite) on augmente la coordoonée X de la tete du serpent
}

void Serpent2::haut(const Terrain & t, unsigned int dir) {
	if(dir==1) { tab[0].x = tab[0].x; tab[0].y = tab[0].y-1;} // si la direction est de 1 (haut) on diminue la coordoonée Y de la tete du serpent
}


void Serpent2::gauche(const Terrain & t, unsigned int dir) {
	if(dir==2)  { tab[0].x = tab[0].x-1; tab[0].y = tab[0].y; } // si la direction est de 2 (gauche) on diminue la coordoonée X de la tete du serpent
}

void Serpent2::bas(const Terrain & t, unsigned int dir) {
	if(dir==3)  { tab[0].x = tab[0].x; tab[0].y = tab[0].y+1; } // si la direction est de 3 (bas) on augmente la coordoonée Y de la tete du serpent
}

void Serpent2::ajouterCorps()
{
    for(unsigned int i=2; i<=taille; i++) { tab[i].c='+'; } //les caracteres du corps du serpent
}

void Serpent2::deplacementCorps()
{
    for(unsigned int i=taille; i>0; i--)
    {
        tab[i].x = tab[i-1].x; //on prend la position X de l'ancienne case occuper par le corps précedent
        tab[i].y = tab[i-1].y; //on prend la position Y de l'ancienne case occuper par le corps précedent
    }
}

bool Serpent2::collisionS() // fonction pour savoir si le serpent se rentre dedans
{
    for(unsigned int i=5; i<taille; i++) //5 car on ne peut pas se rentrer dedans avant  une taille de 5
    {
        if(tab[0].x==tab[i].x && tab[0].y==tab[i].y) // si coordoonée tete du serpent2 dans coordoone de son corps
        {
            return true; // on retourne vrai, il y a collision
        }
    }
    return false;
}

unsigned int Serpent2::getTaille()  { return taille; } // on retourne la taille du serpent
void Serpent2::setTaille(unsigned int a) { taille=a; } //on modifie la taille du serpent

unsigned int Serpent2::getX(unsigned int rang) const { return tab[rang].x; } //on retourne la coordonnée X du serpent en fontion du rang
void Serpent2::setX(unsigned int a) { tab[0].x=a; tab[1].x=a; } //on modifie la coordonnée X de la tete du serpent
unsigned int Serpent2::getY(unsigned int rang) const { return tab[rang].y; } //on retourne la coordonnée Y du serpent en fontion du rang
void Serpent2::setY(unsigned int a) { tab[0].y=a; tab[1].y=a; } //on modifie la coordonnée Y de la tete du serpent
char Serpent2::getC(unsigned int rang) const { return tab[rang].c; } // on recupere le caractere du corps de serpent en fonction de son rang (tete (0 et 1): '@', sinon reste du corps: 'o' )

unsigned int Serpent2::getDirection() const { return direction; } // on retourne la direction du serpent
void Serpent2::setDirection(unsigned int dir) { direction=dir; } //on modifie la direction du serpent

bool Serpent2::getVie() const { return vie;} //on retourne le nombres de points de vie du serpent (0: pas de vie, 1: un point de vie)
void Serpent2::setVie(bool v) { vie=v;} //on modifie le bool pour les points de vie

void Serpent2:: setCorpsX(unsigned int a) { //on deplace les coordonnées X du corps (utiliser dans la procedure respawn dans la class Jeu.cpp)
    for(unsigned int i=2; i<taille; i++)
    {
        tab[i].x=a;
    }
}
void Serpent2:: setCorpsY(unsigned int a) { //on deplace les coordonnées Y du corps (utiliser dans la procedure respawn dans la class Jeu.cpp)
    for(unsigned int i=2; i<taille; i++)
    {
        tab[i].y=a;
    }
}




