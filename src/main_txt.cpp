#include "winTxt.h"
#include "txtJeu.h"
#include <iostream>

using namespace std;

int main ( int argc, char** argv )
{
    termClear();
    Jeu jeu;
    menu(jeu);
    jeu.messageFin();
    termClear();
    return 0;
}
