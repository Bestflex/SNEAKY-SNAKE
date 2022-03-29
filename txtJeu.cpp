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
    MorceauS* a = s.getTab();
	win.print(a[0].x,a[0].y,a[0].c);

	// Affichage du Fruit
	win.print(f.getX(),f.getY(),f.getCharF());

	win.draw();
	delete a;
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
