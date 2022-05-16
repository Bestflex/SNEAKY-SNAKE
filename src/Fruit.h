#ifndef _FRUIT_H
#define _FRUIT_H

#include "Terrain.h"
#include "Serpent.h"
#include "Serpent2.h"
#include "Extra.h"

/// Classe qui gere les fruits
class Fruit{

private:
    /// Charactere pour diff�rencier le type de fruit
    char f;
    /// Position du fruit
    unsigned int x,y;

public:

    /**
     * @brief Constructeur par d�faut de la classe:
       Choisie un fruit de depart avec une position aleatoire correspondant � une zone vide du terrain
     */
    Fruit();

    /**
     * @brief Procedure qui determine l'effet de chaque fruit sur le Serpent.
       Accorde un role � un fruit en fonction du caractere le representant ( exemple : le fruit 'a' permet d'accelerer la vitesse du serpent, ...).
       @param Serpent : la classe Serpent
       @param Terrain : la classe Terrain
       @param Extra : la classe Extra
     */
    void roleFruit(Serpent & s, Terrain & t, Extra & e);

    /**
     * @brief Procedure qui determine l'effet de chaque fruit sur le Serpent2.
       Accorde un role � un fruit en fonction du caractere le representant ( exemple : le fruit 'a' permet d'accelerer la vitesse du serpent2, ...).
       @param Serpent2 : la classe Serpent2
       @param Terrain : la classe Terrain
       @param Extra : la classe Extra
     */
    void roleFruit2(Serpent2 & s2, Terrain & t, Extra & e);

    /**
     * @brief Procedure qui permet de retirer un fruit aleatoirement.
       Choisie un fruit aleatoirement avec une position aleatoire correspondant � une zone vide du terrain
       @param Terrain : la classe Terrain
     */
    void changerFruit( Terrain & t);

    /**
     * @brief Procedure qui permet d'afficher une pomme.
       Fait apparaitre un p aleatoirement dans une case vide du terrain � chaque fois qu'elle est appel�e.
       @param Terrain : la classe Terrain
     */
    void pomme(Terrain & t);

    /**
     * @brief Accesseur : r�cup�re la coordonn�e x du fruit
     */
    unsigned int getX() const;

    /**
     * @brief Accesseur : r�cup�re la coordonn�e y du fruit
     */
    unsigned int getY() const;

    /**
     * @brief Accesseur : r�cup�re le caractere representant le fruit
     */
    char getCharF() const;

    /**
     * @brief Procedure qui teste le fonctionnement du code.
       Permet de tester qu'� chaque fois que le logiciel est modifi�, que les choses qui fonctionnaient avant fonctionnent toujours.
     */
    void FTestRegression();

};

#endif
