#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "Jeu.h"


void txtAff(WinTXT & win, Jeu & j) {
	Terrain& t = j.getTerrain();
	Serpent& s = j.getSerpent();
	Fruit& f = j.getFruit();

	win.clear();

    // Affichage du terrain
	for(unsigned int x=0;x<t.getDimX();++x)
		for(unsigned int y=0;y<t.getDimY();++y)
			win.print(x,y,t.getXY(x,y));

    // Affichage du Serpent
    //MorceauS* a = s.getTab();
    unsigned int x, y;
    unsigned int dir = s.getDirection();
    char c;
    x=s.getX(0);
    y=s.getY(0);
    c=s.getC(0);
    win.print(x,y,c);
	for(unsigned int i=1;i< s.getTaille(); i++)
    {
        if(dir==0)
        {
            x=s.getX(i)-i;
            y=s.getY(i);
            c=s.getC(i);
            win.print(x,y,c);
        }
        if(dir==1)
        {
            x=s.getX(i);
            y=s.getY(i)-i;
            c=s.getC(i);
            win.print(x,y,c);
        }
        if(dir==2)
        {
            x=s.getX(i)+i;
            y=s.getY(i);
            c=s.getC(i);
            win.print(x,y,c);
        }
        if(dir==3)
        {
            x=s.getX(i);
            y=s.getY(i)+i;
            c=s.getC(i);
            win.print(x,y,c);
        }

    }

	// Affichage du Fruit
	win.print(f.getX(),f.getY(),f.getCharF());

	win.draw();

}

void txtBoucle (Jeu & j) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (j.getConstTerrain().getDimX(),j.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,j);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//j.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'q':
				j.actionClavier('q');
				break;
			case 'd':
				j.actionClavier('d');
				break;
			case 'z':
				j.actionClavier('z');
				break;
			case 's':
				j.actionClavier('s');
				break;
			case 'p':
				ok = false;
				break;
		}

	} while (ok);

}
