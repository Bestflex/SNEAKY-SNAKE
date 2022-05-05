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
"~                           ~",
"~      ~~~~~~~~~~~~~~~~     ~",
"~     ~                ~    ~",
"~     ~                ~    ~",
"~     ~                ~    ~",
"~     ~               O~    ~",
"~      ~~~~~~~~~~~~~~~~     ~",
"~                          0~",
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
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
        {
              if (choixT==0){ter[x][y] = terrain1[y][x]; }
              if (choixT==1){ter[x][y] = terrain2[y][x]; }
              if (choixT==2){ter[x][y] = terrain3[y][x]; }
        }
    }
}

void Terrain::changerTerrain()
{
    for(unsigned int i=0;i<dimx;++i)
    {
        for(unsigned int j=0;j<dimy;++j)
        {
              if (choixT==0){ter[i][j] = terrain1[j][i]; }
              if (choixT==1){ter[i][j] = terrain2[j][i]; }
              if (choixT==2){ter[i][j] = terrain3[j][i]; }
              if (choixT==3){ter[i][j] = terrain4[j][i]; }
        }
    }
}

bool Terrain::collisionT(unsigned int x,unsigned int y) const //collision avec le terrain
{
    if((ter[x][y]=='#')){ return true; }
    return false;
}

bool Terrain::collisionTSpecial(unsigned int x,unsigned int y) const//collision mur du terrain4
{
     if((ter[x][y]=='~')){ return true; }
    return false;
}

bool Terrain::collisionTeleporteur1(unsigned int x,unsigned int y) const //collision mur du terrain4
{
    if(ter[x][y]=='0'){return true;}
   return false;
}

bool Terrain::collisionTeleporteur2(unsigned int x,unsigned int y)const //collision mur du terrain4
{
    if(ter[x][y]=='O'){return true;}
   return false;
}

char Terrain::getXY(unsigned int x, unsigned int y) const { return ter[x][y]; }
unsigned int Terrain::getDimX() const { return dimx; }
unsigned int Terrain::getDimY() const { return dimy; }
void Terrain::setChoix(unsigned int a) { choixT = a; }










