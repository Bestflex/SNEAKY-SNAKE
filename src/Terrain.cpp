#include "Terrain.h"
#include <cassert>
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
"#                     ##### #",
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
"#          #######          #",
"#############################",
};

const char terrain4[10][30]{
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"~                          O~",
"~                           ~",
"~~~~~~~~~~~~~~~~~~~~~~~~    ~",
"~             ~             ~",
"~             ~             ~",
"~     ~~~~~~~~~~~~~~~~~~~~~~~",
"~                           ~",
"~                          0~",
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
};

Terrain::Terrain()
{
    srand(time(NULL));

	dimx = 30;
	dimy = 10;
	choixT = rand()%4; //le terrain est choisit aléatoirement
	for(unsigned int x=0;x<dimx;++x)
    {
        for(unsigned int y=0;y<dimy;++y)
        {
              if (choixT==0){ ter[x][y] = terrain1[y][x]; }
              if (choixT==1){ ter[x][y] = terrain2[y][x]; }
              if (choixT==2){ ter[x][y] = terrain3[y][x]; }
	          if (choixT==3){ ter[x][y] = terrain4[y][x]; }
        }
    }
}


bool Terrain::collisionT(unsigned int x,unsigned int y) const //collision avec le terrain
{
    if((ter[x][y]=='#' || ter[x][y]=='~')){ return true; } //si les coordonnées sont sur un caractere # ou ~ on retourne vrai
    return false;
}

bool Terrain::collisionTeleporteur1(unsigned int x,unsigned int y) const //collision teleporteur1 du terrain4
{
    if(ter[x][y]=='0'){return true;} //si les coordonnées sont celle du caractere '0' on retourne vrai
   return false;
}

bool Terrain::collisionTeleporteur2(unsigned int x,unsigned int y)const //collision teleporteur2 du terrain4
{
    if(ter[x][y]=='O'){return true;} //si les coordonnées sont celle du caractere 'O' on retourne vrai
   return false;
}

char Terrain::getXY(unsigned int x, unsigned int y) const { return ter[x][y]; } // on retourne le caractere du terrain a une cordonnée donner
unsigned int Terrain::getDimX() const { return dimx; } // on recupere la dimension X du terrain
unsigned int Terrain::getDimY() const { return dimy; } // on recupere la dimension Y du terrain

void Terrain::TTestRegression()
{
    Terrain t;
   assert(t.dimx==30);
    assert(t.dimy==10);
    assert(t.choixT>=0);
}









