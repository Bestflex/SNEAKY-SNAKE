#include "Jeu.h"
#include "Fruit.h"
#include "Serpent.h"
#include "Serpent2.h"
#include "Extra.h"
#include "Terrain.h"
#include <iostream>

using namespace std;

int main ( int argc, char** argv )
{
	Jeu j;
	Fruit f;
	Serpent s;
	Serpent2 s2;
	Extra e;
	Terrain t;
    j.JTestRegression();
    f.FTestRegression();
    s.STestRegression();
    s2.S2TestRegression();
    e.ETestRegression();
    t.TTestRegression();
    cout << "Tous est en regle" << endl;
	return 0;
}
