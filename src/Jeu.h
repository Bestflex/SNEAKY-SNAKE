#ifndef _JEU_H
#define _JEU_H

#include "Terrain.h"
#include "Serpent.h"
#include "Serpent2.h"
#include "Fruit.h"
#include "Extra.h"

/// Classe qui gere le jeu
class Jeu{

private:
    /// Permet de choisir le gagnant 0 =egalite, 1=joueur1, 2=joueur2
    int gagnantVS;
    /// Choisit entre poser que des pommes ou plusieurs fruits differents, et permet de savoir quel mode de jeux a été lancer
    unsigned int panier;
    /// Classe Terrain
    Terrain t;
    /// Classe Serpent
    Serpent s;
    /// Classe Serpent2
    Serpent2 s2;
    /// Classe Fruit
    Fruit f;
    /// Classe Extra
    Extra e;

public:

    /**
     * @brief Constructeur par défaut de la classe:
       Iniatilise les données de la classe jeu ( gagnantVS = 0, panier = 0 )
     */
    Jeu();

    /**
     * @brief Fonction qui definie l'action des touches du clavier.
       On choisie les touches qui feront deplacer les serpents et on definit leur role.
       @param Touche : charactere stocker dans touche representant les touche du clavier
       @return false
     */
    bool actionClavier(const char touche);

    /**
     * @brief Procedure qui choisie les fruit à afficher.
       En fonction de la variable panier, on choisie si lorsque le serpent mange le fruit on affiche que des pommes ou tous les fruis.
       La procedure quand le serpent mange le fruit lui ajoute un corps, definit l'action que le fruit lui accorde et fait apparaitre un nouveau fruit.
     */
    void choixFruit();

    /**
     * @brief Procedure qui permet de teleporter le serpent.
       On test si le serpent est en contact avec le teleporteur et si c'est le cas on le teleporte.
     */
    void teleporteur();

    /**
     * @brief Fonction qui test quel serpent est rentré dans le corps de l'autre.
       On test pour savoir quel serpent rentre dans l'autre et on retourne la reponse.
       @return 1 si il s'agit du serpent 1 sinon 2
     */
    unsigned int collisionSerpentCorps();

    /**
     * @brief Fonction qui test si les tetes des serpents se percutent.
       On test pour eviter que le serpent rentre en contact avec le fantome du serpent2 en mode solo et savoir quelle message de fin mettre.
       @return true si collision sinon false
     */
    bool collisionTete();

    /**
     * @brief Procedure fait respawn le serpent à la position de base.
       On redefinie les variables du serpent et on le replace à sa position de base.
     */
    void respawn();

    /**
     * @brief Fonction qui test si la partie doit se finir.
       On test toute les condition de defait ou de victoire pour savoir si le jeu doit s'arreter.
       @return false si fin de partie sinon true
     */
    bool finPartie();

    /**
     * @brief Procedure qui definit le message de fin.
       On affiche un message de fonction en fonction du mode de jeu et du perdant.
     */
    void messageFin();

    /**
     * @brief Procedure qui definit le fonctionnement de l'IA.
       On se met à la place de l'IA et on essaie de lui construire un style de jeu en fonction de chaqu'un des cas de figure
       qu'elle peut rencontrer. On la fait ensuite bouger automatiquement .
     */
    void jeuAuto ();

    /**
     * @brief Accesseur : récupère les données de la classe Terrain
     */
    Terrain& getTerrain();

    /**
     * @brief Accesseur : récupère les données de la classe Serpent
     */
    Serpent& getSerpent();

    /**
     * @brief Accesseur : récupère les données de la classe Serpent2
     */
    Serpent2& getSerpent2();

    /**
     * @brief Accesseur : récupère les données de la classe Fruit
     */
    Fruit& getFruit();

    /**
     * @brief Accesseur : récupère les données de la classe Extra
     */
    Extra& getExtra();

    /**
     * @brief Accesseur : récupère le gagnant
     */
    int getGagnant();

    /**
     * @brief Accesseur : récupère le panier
     */
    unsigned int getPanier();

    /**
     * @brief Mutateur : modifie le panier
     */
    void setPanier(unsigned int x);

    /**
     * @brief Procedure qui teste le fonctionnement du code.
       Permet de tester qu'à chaque fois que le logiciel est modifié, que les choses qui fonctionnaient avant fonctionnent toujours.
     */
    void JTestRegression();

};

#endif
