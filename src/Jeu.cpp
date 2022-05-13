#include "Jeu.h"
#include <iostream>
#include <time.h>
using namespace std;
Jeu::Jeu() : t(), s(), s2(), f(), e() { gagnantVS =0; /*egalite*/ panier=0; } // Constructeur par default

Terrain& Jeu::getTerrain() {return t;} // Renvoie les donnees du Terrain
Serpent& Jeu::getSerpent() { return s;} // Renvoie les donnees du Serpent
Serpent2& Jeu::getSerpent2() {return s2;} // Renvoie les donnees du Serpent2
Fruit& Jeu::getFruit() {return f;} // Renvoie les donnees du Fruit
Extra& Jeu::getExtra() {return e;} // Renvoie les donnees du Fruit

bool Jeu::actionClavier (const char touche) { // Definit les actions des touches
	unsigned int a =s.getDirection(); //on recupere la direction du serpent 1
	unsigned int a2=s2.getDirection(); //on recupere la direction du serpent 2
	switch(touche)
	{
		case 'q' : if(a!=0)a=2; s.setDirection(a); break; //si on se deplace vers la droite on ne peut pas se deplacer vers la gauche
		case 'd' : if(a!=2)a=0; s.setDirection(a); break;//si on se deplace vers la gauche on ne peut pas se deplacer vers la droite
		case 'z' : if(a!=3)a=1; s.setDirection(a); break;//si on se deplace vers le bas on ne peut pas aller vers le haut (a!3=bas)
		case 's' : if(a!=1)a=3; s.setDirection(a); break; //si on se deplace vers le haut on ne peut pas aller vers le bas
        case 'k' : if(a2!=0)a2=2; s2.setDirection(a2); break; //pareil que precedement mais avec le serpent2
        case 'm' : if(a2!=2)a2=0; s2.setDirection(a2); break;
        case 'o' : if(a2!=3)a2=1; s2.setDirection(a2); break;
        case 'l' : if(a2!=1)a2=3; s2.setDirection(a2); break;
	} // direction: 0=droite, 1=haut, 2=gauche, 3=bas
	return false;
}


void Jeu::choixFruit()
{
    unsigned int sx0 = s.getX(0); //on recupere les coordonnées de la tete du serpent1 //
    unsigned int sy0 = s.getY(0); //                                                   //

    unsigned int s2x = s2.getX(0); //on recupere les coordonnées de la tete du serpent2  //
    unsigned int s2y = s2.getY(0); //                                                    //

    unsigned int fx = f.getX(); //on recupere les coordonnées du fruit
    unsigned int fy = f.getY();

    if(panier==0) //si jeux solo
    {
        if(sx0 ==fx && sy0==fy) //si la tete du serpent rentre en collision avec le fruit
        {
            s.ajouterCorps(); //on augmente la taille du serpent
            f.roleFruit(s,t,e); //on applique au serpent le bonus du fruit
            f.pomme(t); // pour avoir seulement des fruits de type pomme ('p') qui apparaissent
        }
    }
    else if(panier==1) //jeux solo mode arcarde
    {
        if(sx0 ==fx && sy0==fy)
        {
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.changerFruit(t); // n'importe quel fruit peut apparaitre
        }
    }
    else if(panier==2 || panier==3) //si jeux 1 contre 1 (advresaire joueur ou ia)
    {

          if(sx0 ==fx && sy0==fy)
        {
            s.ajouterCorps();
            f.roleFruit(s,t,e);
            f.changerFruit(t);
        }

          if(s2x ==fx && s2y==fy)
        {
            s2.ajouterCorps();
            f.roleFruit2(s2,t,e);
            f.changerFruit(t);
        }
    }
}

unsigned int Jeu::collisionSerpentCorps() //test quel serpent rentre dans le corps de l'autre
{
    unsigned int serpent;

    for(unsigned int i=2; i<s2.getTaille();i++) //on parcourt tous le corps du serpent2, on commence a 2 car on ne prend pas en compte la tête
    {
        if(s.getX(0)==s2.getX(i) && s.getY(0)==s2.getY(i)) { serpent=1; } //si la tête du serpent1 rentre en collision avec un corps du serpent2
    }
    for(unsigned int j=2; j<s.getTaille();j++)  //on parcourt tous le corps du serpent1, on commence a 2 car on ne prend pas en compte la tête
    {
        if(s2.getX(0)==s.getX(j) && s2.getY(0)==s.getY(j)) { serpent=2; } //si la tête du serpent2 rentre en collision avec un corps du serpent1
    }

    return serpent; // on retourne le serpent qui a heurté le corps de l'autre serpent
}

bool Jeu:: collisionTete() //test si les tetes des serpents se percutent
{
    if(panier==2 || panier==3) //seulement si on joue en 1 contre 1, pour eviter collision avec la tete du serpent2 en solo
    {
        if(s.getX(0)==s2.getX(0) && s.getY(0)==s2.getY(0)){ return true; } //on retourne vrai si il y a collision entre les têtes des deux serpents
    }
    return false;
}

void Jeu:: respawn() //procedure pour remettre les coordonnees et direction initiales des serpents
{
        s.setX(2); //on réinitialise les coordonnées de la tete du serpent1
        s.setY(2);

        s2.setX(t.getDimX()-3); //on réinitialise les coordonnées de la tete du serpent2
        s2.setY(t.getDimY()-3);

        s.setDirection(0); //on réinitialise la direction du serpent1
        s2.setDirection(2);// on réinitialise la direction du serpent2

        s.setCorpsX(-1); //on met les coordonnées du corps du serpent1 hors du terrain pour ne pas gener lors de la remise a 0 des coordonnées de la tête
        s.setCorpsY(-1);
        s2.setCorpsX(-1); //on met les coordonnées du corps du serpent2 hors du terrain pour ne pas gener lors de la remise a 0 des coordonnées de la tête
        s2.setCorpsY(-1);
}

bool Jeu:: finPartie() //toute les conditions pour finir la partie
{
    unsigned int sx0 = s.getX(0); //x de la tete du serpent 1
	unsigned int sy0 = s.getY(0); //y de la tete du serpent 2

	unsigned int s2x0 = s2.getX(0); //x serpent2
	unsigned int s2y0 = s2.getY(0); //y serpent2

	if(s.getTaille()<2) { gagnantVS=2; return false; } // si on tombe en dessous de la taille initial, on perd (si on mange un 'c' (l'image de la bannane en sdl)) //
	if(s2.getTaille()<2) { gagnantVS=1; return false; } //                                                                                                         //

	if(s.collisionS()==true) // si serpent1 se rentre dedans
    {
        if(s.getVie()==0) // si le serpent1 a pas de vie
        {
            gagnantVS=2; //le gagnant est le serpent2
            return false; // on retourne faux pour arreter la partie dans txtJeu et sdlJeux
        }
        else {
             s.setVie(0); //on baisse la vie a 0
             respawn(); ////on appelle la fonction reaparition pour reinitialiser les coordoonnées des serpents pour eviter toute autre collision juste apres
        }

    }

    if(s2.collisionS()==true) // si serpent2 se rentre dedans
    {
        if(s2.getVie()==0) //si le serpent2 a pas de vie
        {
            gagnantVS=1; //le gagnant est le serpent1
            return false;
        }
          else {
                s2.setVie(0); // on baisse la vie du serpent2 a 0
                respawn(); //on appelle la fonction reaparition pour reinitialiser les coordoonnées des serpents pour eviter toute autre collision juste apres
        }
    }

    if(t.collisionT(sx0, sy0) == true)// si serpent1 rentre dans un mur
    {
        if(s.getVie()==0)
        {
            gagnantVS=2; //le gagnant est le serpent2
            return false;
        }
          else {
                s.setVie(0);
                respawn();
        }
    }

    if(t.collisionT(s2x0, s2y0) == true) // si serpent2 rentre dans un mur
    {
        if(s2.getVie()==0)
        {
            gagnantVS=1; //le gagnant est le serpent1
            return false;
        }
          else {
                s2.setVie(0);
               respawn();
        }
    }

    if(panier==2 || panier==3) //les collisions avec le serpent2 sont activer seuleument si le mode de jeux est en 1 contre 1 pour eviter collision avec le corps du serpent2 en solo
        {
            if(collisionSerpentCorps()==1){ //si le serpent1 se rentre dedans
                 if(s.getVie()==0) //on regarde si le serpent1 a une vie ou non
                {
                    gagnantVS=2; //le gagnant est le serpent2
                    return false;
                }
                else {
                    s.setVie(0); //on baisse les points de vie du serpent1 a 0
                    respawn(); // on appelle la fonction respawn pour réinitialiser les coordonnées et direction des serpents
                }
            }
            else if(collisionSerpentCorps()==2) { //si le serpent2 se rentre dedans
                 if(s2.getVie()==0) //on regarde si le serpent2 a une vie ou non
                {
                    gagnantVS=1; //le gagnant est le serpent1
                    return false;
                }
                else {
                    s2.setVie(0); //on baisse les points de vie du serpent2 a 0
                    respawn(); // on appelle la fonction respawn pour réinitialiser les coordonnées et direction des serpents
                }
            }
        }

    if(collisionTete()) // si les tetes des serpents se rentre dedans
    {
        if(s.getVie()==0 && s2.getVie()==0) { return false; } //si les deux serpents non pas de point de vie on arrete la partie
        else if(s.getVie()==1 && s2.getVie()==1) { s.setVie(0); s2.setVie(0); respawn();} //si les deux serpents ont 1 point de vie, on on baisse leurs points de vie puis on les faits réapparaître
        else if(s.getVie()==1 && s2.getVie()==0) { gagnantVS=1; return false;} // si le serpent1 a un point de vie et pas le serpent2 alors le serpent1 a gagner
        else if(s.getVie()==0 && s2.getVie()==1) {gagnantVS=2;return false; } //si le serpent1 n'a pas de point de vie mais le serpent2 oui alors le serpent2 a gagner
    }

    return true;
}

void Jeu::messageFin() //
{
    if(panier==0 || panier==1) //mode de jeux solo, il n'y a qu'un seul serpent
    {
        cout <<"dommage vous avez perdu, votre score est de : "  << e.getScore1() << endl; // on affiche le score du serpent
    }
    else if(panier==2 || panier==3) //mode de jeux 1 contre 1 (joueur ou ia), il y a 2 serpent sur le terrain
    {
        if(gagnantVS==1 || ((gagnantVS==0)&&(e.getScore1()>e.getScore2()))) { cout << "Bravo, vous avez gagne Serpent1" << endl; }//soit serpent2 a perdu, soit egalite mais score du serpent 1 > score serpent2
        else if(gagnantVS==2 || ((gagnantVS==0)&&(e.getScore1()<e.getScore2()))) { cout << "Bravo Serpent2, vous avez gagne" << endl; }
        else if((gagnantVS==0)&&(e.getScore1()==e.getScore2())) cout <<"egalite" <<endl; //pour une egalite il faut que le serpent1 et le serpent2 se rentre dans la tete + meme score + aucun des deux serpents n'a de point de vie
        cout << "le score du serpent1 est de: " << e.getScore1() << endl; //on affiche le score du serpent1
        cout << "le score du serpent2 est de: " << e.getScore2() << endl; //on affiche le score du serpent2
    }

}

void Jeu::teleporteur() //defini ce que fait les teleporteur ('0', 'O' du terrain)
{
    if(t.collisionTeleporteur1(s.getX(0),s.getY(0))){s.setX(26),s.setY(1),s.setDirection(2);} //on change les coordoonnées et la direction du serpent1 a l'endroit de l'autre teleporteur
    if(t.collisionTeleporteur2(s.getX(0),s.getY(0))){s.setX(26),s.setY(8),s.setDirection(2);}
    if(t.collisionTeleporteur1(s2.getX(0),s2.getY(0))){s2.setX(26),s2.setY(1),s2.setDirection(2);} //on change les coordoonnées et la direction du serpent2 a l'endroit de l'autre teleporteur
    if(t.collisionTeleporteur2(s2.getX(0),s2.getY(0))){s2.setX(26),s2.setY(8),s2.setDirection(2);}
}

void Jeu::jeuAuto () { // procedure pour le fonctionnement de l'ia

        srand(time(NULL));
        int directionAleaX=rand()%5;
        int directionAleaY=rand()%5;
        if (directionAleaX ==0 ||directionAleaX ==4) {directionAleaX=2;} //on met une direction aleatoire , 1 chance sur deux pour la direction sur axe X
        else {directionAleaX=0;} // 0 ou 2 car 0=droite et 2=gauche
        if (directionAleaY ==0 ||directionAleaY ==4) {directionAleaY=1;} //on met une direction aleatoire , 1 chance sur deux pour la direction sur axe Y
        else {directionAleaY=3;} // 1 ou 3 car 1=haut et 3=bas

        int dx = f.getX()-s2.getX(0); //savoir la position du fruit en fonction de la position du serpent2 //
        int dy = f.getY()-s2.getY(0); //                                                                   //
        if (dx>0) dx=0; //le fruit est sur la droite du serpent
        if (dx<0) dx=2; //le fruit est sur la gauche du serpent
        if (dy>0) dy=3; //le fruit est en bas du serpent
        if (dy<0) dy=1; //le fruit est en haut du serpent
        if (dx==0) dx=dy; //si le fruit est sur le meme axe x que le serpent alors il se deplace sur l'axe y
        if(dy==0) dy=dx; //si le fruit est sur le meme axe y que le serpent alors il se deplace sur l'axe x

        if(s2.getDirection()==0) // si le serpent va vers la droite
        {
            if((t.collisionT(s2.getX(0)+1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)+1)==false && t.collisionT(s2.getX(0),s2.getY(0)-1)==false)) {s2.setDirection(directionAleaY);} //si mur vers la droite mais pas en haut et en bas, met une direction aleatoire
            else if(t.collisionT(s2.getX(0)+1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)==false) {s2.setDirection(1);} //si mur sur la droite mais pas vers le haut, va en haut
            else if(t.collisionT(s2.getX(0)+1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)) {s2.setDirection(3);}//si mur sur la droite mais pas sur vers le bas, va en bas
            else if(dx!=2 ) {s2.setDirection(dx);} //dx!=2 pour empecher l'ia de faire demi tour (si il va vers la droite, il ne peut pas aller a gauche)
        }
        if(s2.getDirection()==1) // si le serpent va vers le haut
        {
           if((t.collisionT(s2.getX(0),s2.getY(0)-1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false && t.collisionT(s2.getX(0)-1,s2.getY(0))==false)) {s2.setDirection(directionAleaX);}//si mur vers le haut mais pas sur la droite et sur la gauche, met une direction aleatoire
           else if(t.collisionT(s2.getX(0),s2.getY(0)-1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false) {s2.setDirection(0);}//si mur vers le haut mais pas vers la doite, va sur la droite
           else if(t.collisionT(s2.getX(0),s2.getY(0)-1) && t.collisionT(s2.getX(0)+1,s2.getY(0))) {s2.setDirection(2);}//si mur vers le haut mais pas vers la doite, va sur la droite
           else if(dx!=3 ) {s2.setDirection(dy);} //on empeche l'ia de faire demi tour
        }
        if(s2.getDirection()==2) // si le serpent va vers la gauche
        {
           if((t.collisionT(s2.getX(0)-1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)+1)==false && t.collisionT(s2.getX(0),s2.getY(0)-1)==false)) {s2.setDirection(directionAleaY);}
           else if(t.collisionT(s2.getX(0)-1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)==false) {s2.setDirection(1);}
           else if(t.collisionT(s2.getX(0)-1,s2.getY(0)) && t.collisionT(s2.getX(0),s2.getY(0)-1)) {s2.setDirection(3);}
          else if(dx!=0){s2.setDirection(dx);} //on empeche l'ia de faire demi tour
        }
          if(s2.getDirection()==3) // si le serpent va vers le bas
        {
           if((t.collisionT(s2.getX(0),s2.getY(0)+1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false && t.collisionT(s2.getX(0)-1,s2.getY(0))==false)) {s2.setDirection(directionAleaX);}
           else if(t.collisionT(s2.getX(0),s2.getY(0)+1) && t.collisionT(s2.getX(0)+1,s2.getY(0))==false) {s2.setDirection(0);}
           else if(t.collisionT(s2.getX(0),s2.getY(0)+1) && t.collisionT(s2.getX(0)+1,s2.getY(0))) {s2.setDirection(2);}
          else if(dx!=1){s2.setDirection(dy);} //on empeche l'ia de faire demi tour
        }

}

int Jeu::getGagnant(){ return gagnantVS; } //on retourne le gagnant du 1 contre 1
unsigned int Jeu::getPanier() { return panier; } // on retourne l'entier du panier (savoir quel mode de jeux on joue)
void Jeu::setPanier(unsigned int x) { panier=x; } // on modifie le panier (modife le mode de jeux auquel on joue)

