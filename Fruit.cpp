#include "Fruit.h"

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>     // pour l’initialisation avec srand
#include <stdlib.h>   // librairie contenant rand()


using namespace std;

Fruit::Fruit()
{
    srand(time(NULL));
    unsigned int etat=rand()%10;
    Terrain t;

    if (etat==0) { f='p'; }
    else if (etat==1) { f='a'; }
    else if (etat==2) { f='b'; }
    else if (etat==3) { f='c'; }
    else if (etat==4) { f='d'; }
    else if (etat==5) { f='e'; }
    else if (etat==6) { f='f'; }
    else if (etat==7) { f='g'; }
    else if (etat==8) { f='h'; }
    else if (etat==9) { f='i'; }

    do{
        x=rand()%(t.getDimX()-2) +1;
        y=rand()%(t.getDimY()-2) +1;
    }while(t.getXY(x,y)!=' ');

}

void Fruit::roleFruit(Serpent & s)
{
    if(f=='a')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='b')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='c')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='d')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='e')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='f')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='g')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='h')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
    else if(f=='i')
    {
        unsigned int a = s.getTaille()+1;
        s.setTaille(a);
    }
}

void Fruit::changerFruit(Terrain & t)
{
    srand(time(NULL));
    unsigned int etat=rand()%10;

    if (etat==0) { f='p'; }
    else if (etat==1) { f='a'; }
    else if (etat==2) { f='b'; }
    else if (etat==3) { f='c'; }
    else if (etat==4) { f='d'; }
    else if (etat==5) { f='e'; }
    else if (etat==6) { f='f'; }
    else if (etat==7) { f='g'; }
    else if (etat==8) { f='h'; }
    else if (etat==9) { f='i'; }

    do{
        x=rand()%(t.getDimX()-2) +1;
        y=rand()%(t.getDimY()-2) +1;
    }while(t.getXY(x,y)!=' ');
}

unsigned int Fruit::getX() const { return x; }
unsigned int Fruit::getY() const { return y; }
char Fruit::getCharF() const { return f; }
