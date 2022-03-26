#include "Terrain.h"
#include "Serpent.h"
#include "Fruit.h"

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
	for(int x=0;x<dimx;++x)
    {
        for(int y=0;y<dimy;++y){ ter[x][y] = terrain1[dimy-1-y][x]; }
    }
}

bool Terrain::collision(Serpent & s)
{
    bool col;
    MorceauS a[MAX] = {s.getTab()};
    unsigned int x = a[0].x;
    unsigned int y = a[0].y;

    if((ter[x][y]=='#')||(ter[x][y]=='o')){ col = true; }
    else { col = false;}
    return col;
}

void Terrain::mangeFruit(Serpent & s)
{
    MorceauS a[MAX]= {s.getTab()};
    unsigned int x = a[0].x;
    unsigned int y = a[0].y;

    if((ter[x][y]!='#')||(ter[x][y]!='o')||(ter[x][y]!='@')||(ter[x][y]!=' '))
    {
        ter[x][y]=' ';
    }
}

void Terrain::poserFruit(const Fruit & f)
{
    unsigned int x = f.getX();
    unsigned int y = f.getY();
    char c = f.getCharF();
    ter[x][y]= c;
}

/*bool Terrain::estDirectionValide(unsigned int direction) const
{
    return ((x>0) && (x<dimx) && (y>=0) && (y<dimy) && (ter[x][y]!='#'));
}*/

char Terrain::getXY(unsigned int x, unsigned int y) { return ter[x][y]; }
unsigned int Terrain::getDimX() const { return dimx; }
unsigned int Terrain::getDimY() const { return dimy; }









