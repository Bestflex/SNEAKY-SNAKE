#include "winTxt.h"
#include "txtJeu.h"
#include <iostream>

using namespace std;

int main ( int argc, char** argv )
{
    termClear();
	Jeu jeu;
    menu(jeu);
    termClear();
    jeu.messageFin();

	return 0;
}
