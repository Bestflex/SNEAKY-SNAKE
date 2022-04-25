#include "Fruit.h"

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>     // pour l’initialisation avec srand
#include <stdlib.h>   // librairie contenant rand()


using namespace std;

Fruit::Fruit() // Constructeur par default a
{
    srand(time(NULL));
    Terrain t;

    f='p'; // Place un fruit p
    do{
        x=rand()%(t.getDimX()-2) +1; // Position aleatoire
        y=rand()%(t.getDimY()-2) +1; // Position aleatoire
    }while(t.getXY(x,y)!=' '); // Tant que la zone du terrain est vide

}

void Fruit::roleFruit(Serpent & s, Terrain & t, Extra & e) // Determine l'effet de chaque fruit sur le Serpent 1
{
    unsigned int a, b;
    unsigned int score = e.getScore1();
    double temps = e.getTime1();
    if(f=='a') {  s.setTaille(s.getTaille()+1); e.setTime1(temps/2.0); e.setScore1(score+1); } // accelere le serpent
    else if(f=='b') { s.setTaille(s.getTaille()+1); e.setScore1(score+2); } // augmente le score de 2
    else if(f=='c') { s.setTaille(s.getTaille()-1); e.setScore1(score-1); } // reduit la taille du serpent de 1
    else if(f=='d') { s.setTaille(s.getTaille()+1); e.setTime1(temps*2.0); e.setScore1(score+1); } // ralentit le serpent
    else if(f=='e') { s.setTaille(s.getTaille()+1); e.setScore1(score+1); }
    else if(f=='f') { s.setTaille(s.getTaille()+1); e.setScore1(score+1); }
    else if(f=='t') { s.setTaille(s.getTaille()+1); e.setScore1(score+1);   // teleporte le serpent à un lieux random
        do{
            a=rand()%(t.getDimY()-2) +1; b=rand()%(t.getDimY()-2) +1; // Position aleatoire
            s.setX(a); s.setY(b); // Modification des coordonnees de la tete
        }while(t.getXY(a,b)!=' '); } // Tant que la zone du terrain est vide

    else if(f=='p') { s.setTaille(s.getTaille()+1); e.setTime1(0.2); e.setScore1(score+1); } // Augmente juste la taille de 1
}

void Fruit::roleFruit2(Serpent2 & s2, Terrain & t, Extra & e) // Determine l'effet de chaque fruit sur le Serpent 1
{
    unsigned int a, b;
    unsigned int score = e.getScore2();
    if(f=='a') {  s2.setTaille(s2.getTaille()+1); e.setTime2(0.1); e.setScore2(score+1); } // accelere le serpent
    else if(f=='b') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.2); e.setScore2(score+2); } // augmente le score de 2
    else if(f=='c') { s2.setTaille(s2.getTaille()-1); e.setTime2(0.1); e.setScore2(score-1); } // reduit la taille du serpent de 1
    else if(f=='d') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.2); e.setScore2(score+1); } // ralentit le serpent
    else if(f=='e') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.1); e.setScore2(score+1); }
    else if(f=='f') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.1); e.setScore2(score+1); }
    else if(f=='t') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.1); e.setScore2(score+1);   // teleporte le serpent à un lieux random
        do{
            a=rand()%(t.getDimY()-2) +1; b=rand()%(t.getDimY()-2) +1; // Position aleatoire
            s2.setX(a); s2.setY(b); // Modification des coordonnees de la tete
        }while(t.getXY(a,b)!=' '); } // Tant que la zone du terrain est vide

    else if(f=='p') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.2); e.setScore2(score+1); } // Augmente juste la taille de 1
}

void Fruit::changerFruit(Terrain & t) // Permet de tirer un nouveau fruit aleatoirement
{
    srand(time(NULL));
    unsigned int etat=rand()%10; // Tire un chiffre aleatoirement entre 0 et 9

    if (etat==0) { f='p'; } // On associe chaque fruit à un etat
    else if (etat==1) { f='a'; }
    else if (etat==2) { f='b'; }
    else if (etat==3) { f='c'; }
    else if (etat==4) { f='d'; }
    else if (etat==5) { f='e'; }
    else if (etat==6) { f='f'; }
    else if (etat==9) { f='t'; }

    do{
        x=rand()%(t.getDimX()-2) +1; // Position aleatoire
        y=rand()%(t.getDimY()-2) +1; // Position aleatoire
    }while(t.getXY(x,y)!=' '); // Tant que la zone du terrain est vide
}

void Fruit::pomme(Terrain & t) // Permet de remmetre une pomme
{
    srand(time(NULL));
    f='d';
    do{
        x=rand()%(t.getDimX()-2) +1; // Position aleatoire
        y=rand()%(t.getDimY()-2) +1; // Position aleatoire
    }while(t.getXY(x,y)!=' '); // Tant que la zone du terrain est vide
}

unsigned int Fruit::getX() const { return x; } // Recupere le parametre prive x
unsigned int Fruit::getY() const { return y; } // Recupere le parametre prive y
char Fruit::getCharF() const { return f; } // Recupere le parametre prive f
