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
    WinTXT win (j.getTerrain().getDimX(),j.getTerrain().getDimY());
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
		//cout << diff.count() <<endl;
		if(diff.count() > t1)
        {
            switch (a)  {
                case 2:  s.gauche(a);  break;
                case 0:  s.droite(a);  break;
                case 1:  s.haut(a);  break;
                case 3:  s.bas(a);  break;
                case 'p': break;
            }
            s.deplacementCorps();
            ok=j.finPartie();
            j.teleporteur();
            j.choixFruit();
            start = std::chrono::steady_clock::now();
            cout << "Score : " << e.getScore1() <<endl;
            if(j.getPanier()==1) {cout << "Point de vie serpent1 : " << s.getVie() << endl;}
        }

	} while (ok);
}

void txtBoucleVS (Jeu & j) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (j.getTerrain().getDimX(),j.getTerrain().getDimY());
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

		unsigned int direction=s.getDirection();
		unsigned int direction2=s2.getDirection();
		c = win.getCh();
		j.actionClavier(c);

		double t1 = e.getTime1();
        double t2 = e.getTime2();
		auto fin = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = fin - start;
		std::chrono::duration<double> diff2 = fin - start2;
		if(diff.count() > t1)
        {
            switch (direction)  {
                case 2:  s.gauche(direction);  break;
                case 0:  s.droite(direction);  break;
                case 1:  s.haut(direction);  break;
                case 3:  s.bas(direction);  break;
                case 'p': break;
            }
            s.deplacementCorps();
            ok=j.finPartie();
            j.choixFruit();
            j.teleporteur();
            start = std::chrono::steady_clock::now();
            cout << "Score serpent1 : " << e.getScore1() <<endl;
            cout << "Point de vie serpent1 : " << s.getVie() << endl;
        }
        if(diff2.count() > t2)
        {
            switch (direction2)  {
                case 2:  s2.gauche(direction2);  break;
                case 0:  s2.droite(direction2);  break;
                case 1:  s2.haut(direction2);  break;
                case 3:  s2.bas(direction2);  break;
                case 'p': break;

            }
            if(j.getPanier()==3) {j.jeuAuto();} //jeu contre l'ia si le panier est a 3
            s2.deplacementCorps();
            ok=j.finPartie();
            j.choixFruit();
            j.teleporteur();
            start2 = std::chrono::steady_clock::now();
            cout << "Score serpent 2: " << e.getScore2() <<endl;
            cout << "Point de vie serpent2 : " << s2.getVie() << endl;
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
    cout << "Tappez 3 pour le mode ArcadeVs l'ia" << endl;
    cout << "Tappez 4 pour fermer la fenetre" << endl;
    cin >> choix;
    termClear();

    do
    {
        switch (choix)
        {
            case 0 : j.setPanier(0);txtBoucleSOLO(j); ok=j.finPartie(); break;
            case 1 : j.setPanier(1); txtBoucleSOLO(j); ok=j.finPartie(); break;
            case 2 : j.setPanier(2); txtBoucleVS(j); ok=j.finPartie(); break;
            case 3 : j.setPanier(3); txtBoucleVS(j); ok=j.finPartie(); break;
            default : cout << "Aucun choix n'a ete fait" << endl;
        }
    }while(ok);
}
