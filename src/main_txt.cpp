#include "winTxt.h"
#include "txtJeu.h"
#include <iostream>

using namespace std;

int main ( int argc, char** argv )
{
    termClear();
	Jeu jeu;
	//txtBoucleSOLO(jeu);
    menu(jeu);
    termClear();
    if(jeu.getGagnant()==1) { cout << "Bravo, vous avez gagne Serpent1" << endl; }
    else if(jeu.getGagnant()==2) { cout << "Bravo Serpent2, vous avez gagne" << endl; }
    else cout <<"egalite" <<endl;

	return 0;
}
