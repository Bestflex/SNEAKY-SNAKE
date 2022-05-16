#include "Fruit.h"
#include <cassert>
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
    else if(f=='c') { s.setTaille(s.getTaille()-1); e.setScore1(score+1); } // reduit la taille du serpent de 1
    else if(f=='d') { s.setTaille(s.getTaille()+1); e.setTime1(temps*2.0); e.setScore1(score+1); } // ralentit le serpent
    else if(f=='t') { s.setTaille(s.getTaille()+1); e.setScore1(score+1);   // teleporte le serpent à un lieux random
        do{
            a=rand()%(t.getDimY()-2) +1; b=rand()%(t.getDimY()-2) +1; // Position aleatoire
            s.setX(a); s.setY(b); // Modification des coordonnees de la tete
        }while(t.getXY(a,b)!=' '); } // Tant que la zone du terrain est vide

    else if(f=='p') { s.setTaille(s.getTaille()+1); e.setTime1(0.2); e.setScore1(score+1); } // Augmente juste la taille de 1 et reinitialise la vitesse (si on a manger un 'a'(piment==accelere) ou un 'd'(glace)==ralentit)
    else if(f=='8') {s.setVie(1); e.setScore1(score+1);} //on gagne un point de vie (ne se cumule pas)
}

void Fruit::roleFruit2(Serpent2 & s2, Terrain & t, Extra & e) // Determine l'effet de chaque fruit sur le Serpent 1
{
    unsigned int a, b;
    unsigned int score = e.getScore2();
    if(f=='a') {  s2.setTaille(s2.getTaille()+1); e.setTime2(0.1); e.setScore2(score+1); } // accelere le serpent
    else if(f=='b') { s2.setTaille(s2.getTaille()+1); e.setScore2(score+2); } // augmente le score de 2
    else if(f=='c') { s2.setTaille(s2.getTaille()-1); e.setScore2(score+1); } // reduit la taille du serpent de 1
    else if(f=='d') { s2.setTaille(s2.getTaille()+1); e.setScore2(score+1); } // ralentit le serpent
    else if(f=='t') { s2.setTaille(s2.getTaille()+1); e.setScore2(score+1);   // teleporte le serpent à un lieux random
        do{
            a=rand()%(t.getDimY()-2) +1; b=rand()%(t.getDimY()-2) +1; // Position aleatoire
            s2.setX(a); s2.setY(b); // Modification des coordonnees de la tete
        }while(t.getXY(a,b)!=' '); } // Tant que la zone du terrain est vide

    else if(f=='p') { s2.setTaille(s2.getTaille()+1); e.setTime2(0.2); e.setScore2(score+1); } // Augmente juste la taille de 1 et reinitialise la vitesse (si on a manger un 'a'(piment==accelere) ou un 'd'(glace)==ralentit)
    else if(f=='8') { s2.setVie(1);e.setScore2(score+1);} // on gagne un point de vie (ne se cumule pas)
}

void Fruit::changerFruit(Terrain & t) // Permet de tirer un nouveau fruit aleatoirement
{
    srand(time(NULL));
    unsigned int etat=rand()%14; // Tire un chiffre aleatoirement entre 0 et 6

    if (etat==0 || etat==1 || etat==2) { f='p'; } // On associe chaque fruit à un etat
    else if (etat==3 || etat==4) { f='a'; }
    else if (etat==5 || etat==6) { f='b'; }
    else if (etat==7 || etat==8) { f='c'; }
    else if (etat==9 || etat==10) { f='d'; }
    else if (etat==11 || etat==12) { f='t'; }
    else if (etat==13) { f='8';}
    do{
        x=rand()%(t.getDimX()-2) +1; // Position aleatoire
        y=rand()%(t.getDimY()-2) +1; // Position aleatoire
    }while(t.getXY(x,y)!=' '); // Tant que la zone du terrain est vide
}

void Fruit::pomme(Terrain & t) // Permet de remmetre une pomme
{
    srand(time(NULL));
    f='p';
    do{
        x=rand()%(t.getDimX()-2) +1; // Position aleatoire
        y=rand()%(t.getDimY()-2) +1; // Position aleatoire
    }while(t.getXY(x,y)!=' '); // Tant que la zone du terrain est vide
}

unsigned int Fruit::getX() const { return x; } // Recupere le parametre prive x
unsigned int Fruit::getY() const { return y; } // Recupere le parametre prive y
char Fruit::getCharF() const { return f; } // Recupere le parametre prive f

void Fruit::FTestRegression()
{
    Fruit f;
    assert(f.f=='p');
    assert((f.x>0)&&(f.x<30));
    assert((f.y>0)&&(f.y<10));
}
