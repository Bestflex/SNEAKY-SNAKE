#ifndef _SERPENT2_H
#define _SERPENT2_H


#include "Terrain.h"


const int MAX2 = 200;

/// Structure MorceauS2
struct MorceauS2
{
    /// Charactere representant le serpent2
    char c;
    /// Coordonnées du morceau de serpent2
    unsigned int x,y;
};

/// Classe qui gere le deuxieme Serpent
class Serpent2{
private:

    /// Tableau de Morceau de serpent2
    MorceauS2 tab[MAX2];
    /// Taille du serpent2
    unsigned int taille;
    /// Direction du serpent2
    unsigned int direction;
    /// Vie du serpent2
    bool vie;

public :


    /**
     * @brief Constructeur par défaut de la classe:
       Initialise les variables du serpent2 ( Coordonnée de la tete, la taille du serpent2, sa direction de base, le charactere representant la tete, la vie bonus à 0, ...)
     */
    Serpent2();

    /**
     * @brief Procedure qui deplace le serpent2 à droite.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent2 d'une case vers la droite.
       @param Terrain : la classe Terrain
       @param dir : entié superieur ou egal à 0
     */
    void droite(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent2 à haut.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent2 d'une case vers la haut.
       @param Terrain : la classe Terrain
       @param dir : entié superieur ou egal à 0
     */
    void haut(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent2 à gauche.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent2 d'une case vers la gauche.
       @param Terrain : la classe Terrain
       @param dir : entié superieur ou egal à 0
     */
    void gauche(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent2 à bas.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent2 d'une case vers la bas.
       @param Terrain : la classe Terrain
       @param dir : entié superieur ou egal à 0
     */
    void bas(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui ajoute un corps au serpent2.
       La Procedure permet de quand elle est appelée d'ajouter un corps au serpent2.
     */
    void ajouterCorps();

    /**
     * @brief Procedure qui deplace le corps du serpent2.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du corps du serpent2 à la case anciennement occupé par un membre du serpent2.
     */
    void deplacementCorps();

    /**
     * @brief Fonction qui test les collisions du serpent2.
       La Fonction qui test si le serpent2 rentre dans son corps à partir d'une taille egal à 5 (taille à partir de laquelle le serpent2 peut rentrer dans son corps.
       @return true si collision sinon false
     */
    bool collisionS();

    /**
     * @brief Accesseur : récupère la taille du serpent2
     */
    unsigned int getTaille();

    /**
     * @brief Accesseur : récupère la coordonnée x du morceau choisie
       @param rang : entié superieur ou egal à 0 qui represente le rang du morceau du serpent2 choisie dans le tableau
     */
    unsigned int getX(unsigned int rang) const;

    /**
     * @brief Accesseur : récupère la coordonnée y du morceau choisie
       @param rang : entié superieur ou egal à 0 qui represente le rang du morceau du serpent2 choisie dans le tableau
     */
    unsigned int getY(unsigned int rang) const;

    /**
     * @brief Accesseur : récupère le charactere c du morceau choisie
       @param rang : entié superieur ou egal à 0 qui represente le rang du morceau du serpent2 choisie dans le tableau
     */
    char getC(unsigned int rang) const;

    /**
     * @brief Accesseur : récupère la direction du serpent2
     */
    unsigned int getDirection() const;

    /**
     * @brief Accesseur : récupère le booleen indiquant si le serpent2 à une vie ou non
     */
    bool getVie() const ;

    /**
     * @brief Mutateur : modifie la taille du Serpent2
     */
    void setTaille(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonnée x du Serpent2
     */
    void setX(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonnée y du Serpent2
     */
    void setY(unsigned int a);

    /**
     * @brief Mutateur : modifie la direction du Serpent2
     */
    void setDirection(unsigned int dir);

    /**
     * @brief Mutateur : modifie le bool representant la vie du Serpent2
     */
    void setVie(bool x);

    /**
     * @brief Mutateur : modifie la coordonnée x du corps du Serpent2
     */
    void setCorpsX(unsigned int x);

    /**
     * @brief Mutateur : modifie la coordonnée y du corps du Serpent2
     */
    void setCorpsY(unsigned int y);
};

#endif // Serpent2.h
