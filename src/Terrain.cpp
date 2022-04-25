#include "Terrain.h"

#include <time.h>     // pour l’initialisation avec srand
#include <stdlib.h>   // librairie contenant rand()

const char terrain1[10][30]{
"#############################",
"#                           #",
"#                           #",
"#                           #",
"#                           #",
"#                           #",
"#                           #",
"#                           #",
"#                           #",
"#############################",
};

const char terrain2[10][30]{
"#############################",
"#                           #",
"#                     #######",
"#    #                  #   #",
"#     #                 #   #",
"#      #                 #  #",
"#       ######              #",
"#         #            #    #",
"#                           #",
"#############################",
};

const char terrain3[10][30]{
"#############################",
"#         ##                #",
"#            #####    ###   #",
"#       ##                  #",
"###        #######          #",
"#                   #       #",
"# #        #######   #   ####",
"#  #    #                   #",
"#  #       #######          #",
"#############################",
};


Terrain::Terrain()
{
    srand(time(NULL));

	dimx = 30;
	dimy = 10;
	choixT = rand()%3;
	for(unsigned int x=0;x<dimx;++x)
    {
        for(unsigned int y=0;y<dimy;++y)
        {     if (choixT==0){ter[x][y] = terrain1[y][x]; }
              if (choixT==1){ter[x][y] = terrain2[y][x]; }
              if (choixT==2){ter[x][y] = terrain3[y][x]; }
        }
    }
}

bool Terrain::collisionT(unsigned int x,unsigned int y) //collision avec le terrain
{
    if((ter[x][y]=='#')){ return true; }
    return false;
}

void Terrain::mangeFruit(const unsigned int x,const unsigned int y) { ter[x][y]=' '; }

//void Terrain::poserFruit(unsigned int x,unsigned int y,char c) { ter[x][y]= c; }

char Terrain::getXY(unsigned int x, unsigned int y) { return ter[x][y]; }
unsigned int Terrain::getDimX() const { return dimx; }
unsigned int Terrain::getDimY() const { return dimy; }
void Terrain::setChoix(unsigned int a) { choixT = a; }










