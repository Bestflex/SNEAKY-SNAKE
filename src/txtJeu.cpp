#include <iostream>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "Jeu.h"

using namespace std;

void txtAffSOLO(WinTXT & win, Jeu & j) {
	Terrain& t = j.getTerrain();
	Serpent& s = j.getSerpent();
	Fruit& f = j.getFruit();

	win.clear();

    // Affichage du terrain
	for(unsigned int x=0;x<t.getDimX();++x)
		for(unsigned int y=0;y<t.getDimY();++y)
			win.print(x,y,t.getXY(x,y));

    // Affichage du Serpent
    unsigned int x, y;
    char c;
	for(unsigned int i=0;i<s.getTaille(); i++)
    {
        x=s.getX(i);
        y=s.getY(i);
        c=s.getC(i);
        win.print(x,y,c);
    }

	// Affichage du Fruit
	win.print(f.getX(),f.getY(),f.getCharF());

	win.draw();

}

void txtAffVS(WinTXT & win, Jeu & j) {
	Terrain& t = j.getTerrain();
	Serpent& s = j.getSerpent();
	Serpent2& s2 = j.getSerpent2();
	Fruit& f = j.getFruit();

	win.clear();

    // Affichage du terrain
	for(unsigned int x=0;x<t.getDimX();++x)
		for(unsigned int y=0;y<t.getDimY();++y)
			win.print(x,y,t.getXY(x,y));

    // Affichage du Serpent
    unsigned int x, y;
    char c;
	for(unsigned int i=0;i<s.getTaille(); i++)
    {
        x=s.getX(i);
        y=s.getY(i);
        c=s.getC(i);
        win.print(x,y,c);
    }

    // Affichage du Serpent2
    unsigned int x2, y2;
    char c2;
	for(unsigned int i=0;i<s2.getTaille(); i++)
    {
        x2=s2.getX(i);
        y2=s2.getY(i);
        c2=s2.getC(i);
        win.print(x2,y2,c2);
    }

	// Affichage du Fruit
	win.print(f.getX(),f.getY(),f.getCharF());

	win.draw();
}

void txtBoucleSOLO (Jeu & j) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (j.getConstTerrain().getDimX(),j.getConstTerrain().getDimY());
    Terrain& t = j.getTerrain();
	Serpent& s = j.getSerpent();
	Extra& e = j.getExtra();
	char c;
	auto start = std::chrono::steady_clock::now();
    bool ok=j.finPartie();
	do {
	    txtAffSOLO(win,j);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		unsigned int a=s.getDirection();
		c = win.getCh();
		j.actionClavier(c);
		double t1 = e.getTime1();
		auto fin = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = fin - start;
		cout << diff.count() <<endl;
		if(diff.count() > t1)
        {
            switch (a)  {
                case 2:  s.gauche(t,a);  break;
                case 0:  s.droite(t,a);  break;
                case 1:  s.haut(t,a);  break;
                case 3:  s.bas(t,a);  break;
                case 'p': break;
            }
            s.deplacementCorps();
            ok=j.finPartie();
            j.choixFruit(j.getPanier());
            start = std::chrono::steady_clock::now();
            cout << "Score : " << e.getScore1() <<endl;
        }

	} while (ok);
}

void txtBoucleVS (Jeu & j) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (j.getConstTerrain().getDimX(),j.getConstTerrain().getDimY());
    Terrain& t = j.getTerrain();
	Serpent& s = j.getSerpent();
	Serpent2& s2 = j.getSerpent2();
	Extra& e = j.getExtra();
	int c;
    bool ok;

    auto start = std::chrono::steady_clock::now();
    auto start2 = std::chrono::steady_clock::now();
	do {
	    txtAffVS(win,j);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		unsigned int a=s.getDirection();
		unsigned int b=s2.getDirection();
		c = win.getCh();
		j.actionClavier(c);
		double t1 = e.getTime1();
        double t2 = e.getTime2();
		auto fin = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = fin - start;
		std::chrono::duration<double> diff2 = fin - start2;
		if(diff.count() > t1)
        {
            switch (a)  {
                case 2:  s.gauche(t,a);  break;
                case 0:  s.droite(t,a);  break;
                case 1:  s.haut(t,a);  break;
                case 3:  s.bas(t,a);  break;
                case 'p': break;
            }
            s.deplacementCorps();
            ok=j.finPartie();
            j.choixFruit(j.getPanier());
            start = std::chrono::steady_clock::now();
            cout << "Score serpent1 : " << e.getScore1() <<endl;
        }
        if(diff2.count() > t2)
        {
            switch (b)  {
                case 2:  s2.gauche(t,b);  break;
                case 0:  s2.droite(t,b);  break;
                case 1:  s2.haut(t,b);  break;
                case 3:  s2.bas(t,b);  break;
                case 'p': break;
            }
            s2.deplacementCorps();
            ok=j.finPartie();
            j.choixFruit(j.getPanier());
            start2 = std::chrono::steady_clock::now();
            cout << "Score serpent 2: " << e.getScore2() <<endl;
        }
	} while (ok);
}

void menu(Jeu & j)
{
    int choix;
    bool ok;
    cout << "Veuillez choisir votre mode de jeu !!" << endl;
    cout << "Tappez 0 pour le mode Basique" << endl;
    cout << "Tappez 1 pour le mode Arcade" << endl;
    cout << "Tappez 2 pour le mode ArcadeVS" << endl;
    cout << "Tappez 3 pour fermer la fenetre" << endl;
    cin >> choix;
    termClear();

    do
    {
        switch (choix)
        {
            case 0 : j.setPanier(0);txtBoucleSOLO(j); ok=j.finPartie(); break;
            case 1 : j.setPanier(1); txtBoucleSOLO(j); ok=j.finPartie(); break;
            case 2 : j.setPanier(1); txtBoucleVS(j); ok=j.finPartie(); break;
            default : cout << "Aucun choix n'a ete fait" << endl;
        }
    }while(ok);
}
