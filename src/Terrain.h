#ifndef _TERRAIN_H
#define _TERRAIN_H



class Terrain{

private:
    unsigned int dimx;
	unsigned int dimy;
	unsigned int choixT;
	char ter[100][100];

public:
    Terrain();

    bool collisionT(unsigned int x,unsigned int y); // test collision avec mur et corps
    void mangeFruit(const unsigned int x,const unsigned int y);
    //void poserFruit(unsigned int x,unsigned int y,char c);
    char getXY(unsigned int x,unsigned int y); //renvoie le type d'objet a une position x,y;
    unsigned int getDimX() const;
    unsigned int getDimY() const;
    void setChoix(unsigned int a);

};

#endif
