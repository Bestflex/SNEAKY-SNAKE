#ifndef _FRUIT_H
#define _FRUIT_H

#include "Terrain.h"
#include "Serpent.h"
#include "Serpent2.h"
#include "Extra.h"

/// Classe qui gere les fruits
class Fruit{

private:
    /// Charactere pour différencier le type de fruit
    char f;
    /// Position du fruit
    unsigned int x,y;

public:

    /**
     * @brief Constructeur par défaut de la classe:
       Choisie un fruit de depart avec une position aleatoire correspondant à une zone vide du terrain
     */
    Fruit();

    /**
     * @brief Procedure qui determine l'effet de chaque fruit sur le Serpent.
       Accorde un role à un fruit en fonction du caractere le representant ( exemple : le fruit 'a' permet d'accelerer la vitesse du serpent, ...).
       @param Serpent : la classe Serpent
       @param Terrain : la classe Terrain
       @param Extra : la classe Extra
     */
    void roleFruit(Serpent & s, Terrain & t, Extra & e);

    /**
     * @brief Procedure qui determine l'effet de chaque fruit sur le Serpent2.
       Accorde un role à un fruit en fonction du caractere le representant ( exemple : le fruit 'a' permet d'accelerer la vitesse du serpent2, ...).
       @param Serpent2 : la classe Serpent2
       @param Terrain : la classe Terrain
       @param Extra : la classe Extra
     */
    void roleFruit2(Serpent2 & s2, Terrain & t, Extra & e);

    /**
     * @brief Procedure qui permet de retirer un fruit aleatoirement.
       Choisie un fruit aleatoirement avec une position aleatoire correspondant à une zone vide du terrain
       @param Terrain : la classe Terrain
     */
    void changerFruit( Terrain & t);

    /**
     * @brief Procedure qui permet d'afficher une pomme.
       Fait apparaitre un p aleatoirement dans une case vide du terrain à chaque fois qu'elle est appelée.
       @param Terrain : la classe Terrain
     */
    void pomme(Terrain & t);

    /**
     * @brief Accesseur : récupère la coordonnée x du fruit
     */
    unsigned int getX() const;

    /**
     * @brief Accesseur : récupère la coordonnée y du fruit
     */
    unsigned int getY() const;

    /**
     * @brief Accesseur : récupère le caractere representant le fruit
     */
    char getCharF() const;

    /**
     * @brief Procedure qui teste le fonctionnement du code.
       Permet de tester qu'à chaque fois que le logiciel est modifié, que les choses qui fonctionnaient avant fonctionnent toujours.
     */
    void FTestRegression();

};

#endif
