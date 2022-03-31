#ifndef _TERRAIN_H
#define _TERRAIN_H



class Terrain{

private:
    unsigned int dimx;
	unsigned int dimy;
	char ter[100][100];

public:
    Terrain();

    bool collision(unsigned int x,unsigned int y); // test collision avec mur et corps
    void mangeFruit(const unsigned int x,const unsigned int y);
    //void poserFruit(unsigned int x,unsigned int y,char c);
    bool estDirectionValide(unsigned int direction) const;

    char getXY(unsigned int x,unsigned int y); //renvoie le type d'objet a une position x,y;
    unsigned int getDimX() const;
    unsigned int getDimY() const;

};

#endif
