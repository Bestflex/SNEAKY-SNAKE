#include "Terrain.h"

const char terrain1[10][20]{
"###################",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"###################",

};


Terrain::Terrain() {
	dimx = 10;
	dimy = 20;
	for(unsigned int x=0;x<dimx;++x)
    {
        for(unsigned int y=0;y<dimy;++y){ ter[x][y] = terrain1[dimy-1-y][x]; }
    }
}

bool Terrain::collision(unsigned int x,unsigned int y)
{
    bool col;

    if((ter[x][y]=='#')||(ter[x][y]=='o')){ col = true; }
    else { col = false;}
    return col;
}

void Terrain::mangeFruit(const unsigned int x,const unsigned int y) { ter[x][y]=' '; }


void Terrain::poserFruit(unsigned int x,unsigned int y,char c) { ter[x][y]= c; }

bool Terrain::estDirectionValide(unsigned int dir) const
{
    bool dep;
    if(dir==0)
    {
        while(dir!=2) { dep = true;}
    }
    else if(dir==1)
    {
        while(dir!=3) {dep = true;}
    }
    else if(dir==2)
    {
        while(dir!=0) {dep = true;}
    }
    else if(dir==3)
    {
        while(dir!=1) {dep = true;}
    }else {dep = false;}
    return dep;
}

char Terrain::getXY(unsigned int x, unsigned int y) { return ter[x][y]; }
unsigned int Terrain::getDimX() const { return dimx; }
unsigned int Terrain::getDimY() const { return dimy; }
//char** Terrain::getTerrain() { return ter;}









