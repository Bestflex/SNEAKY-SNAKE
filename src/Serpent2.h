#ifndef _SERPENT2_H
#define _SERPENT2_H


#include "Terrain.h"


const int MAX2 = 200;

/// Structure MorceauS2
struct MorceauS2
{
    /// Charactere representant le serpent2
    char c;
    /// Coordonn�es du morceau de serpent2
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
     * @brief Constructeur par d�faut de la classe:
       Initialise les variables du serpent2 ( Coordonn�e de la tete, la taille du serpent2, sa direction de base, le charactere representant la tete, la vie bonus � 0, ...)
     */
    Serpent2();

    /**
     * @brief Procedure qui deplace le serpent2 � droite.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent2 d'une case vers la droite.
       @param Terrain : la classe Terrain
       @param dir : enti� superieur ou egal � 0
     */
    void droite(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent2 � haut.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent2 d'une case vers la haut.
       @param Terrain : la classe Terrain
       @param dir : enti� superieur ou egal � 0
     */
    void haut(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent2 � gauche.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent2 d'une case vers la gauche.
       @param Terrain : la classe Terrain
       @param dir : enti� superieur ou egal � 0
     */
    void gauche(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent2 � bas.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent2 d'une case vers la bas.
       @param Terrain : la classe Terrain
       @param dir : enti� superieur ou egal � 0
     */
    void bas(const Terrain & t, unsigned int dir);

    /**
     * @brief Procedure qui ajoute un corps au serpent2.
       La Procedure permet de quand elle est appel�e d'ajouter un corps au serpent2.
     */
    void ajouterCorps();

    /**
     * @brief Procedure qui deplace le corps du serpent2.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du corps du serpent2 � la case anciennement occup� par un membre du serpent2.
     */
    void deplacementCorps();

    /**
     * @brief Fonction qui test les collisions du serpent2.
       La Fonction qui test si le serpent2 rentre dans son corps � partir d'une taille egal � 5 (taille � partir de laquelle le serpent2 peut rentrer dans son corps.
       @return true si collision sinon false
     */
    bool collisionS();

    /**
     * @brief Accesseur : r�cup�re la taille du serpent2
     */
    unsigned int getTaille();

    /**
     * @brief Accesseur : r�cup�re la coordonn�e x du morceau choisie
       @param rang : enti� superieur ou egal � 0 qui represente le rang du morceau du serpent2 choisie dans le tableau
     */
    unsigned int getX(unsigned int rang) const;

    /**
     * @brief Accesseur : r�cup�re la coordonn�e y du morceau choisie
       @param rang : enti� superieur ou egal � 0 qui represente le rang du morceau du serpent2 choisie dans le tableau
     */
    unsigned int getY(unsigned int rang) const;

    /**
     * @brief Accesseur : r�cup�re le charactere c du morceau choisie
       @param rang : enti� superieur ou egal � 0 qui represente le rang du morceau du serpent2 choisie dans le tableau
     */
    char getC(unsigned int rang) const;

    /**
     * @brief Accesseur : r�cup�re la direction du serpent2
     */
    unsigned int getDirection() const;

    /**
     * @brief Accesseur : r�cup�re le booleen indiquant si le serpent2 � une vie ou non
     */
    bool getVie() const ;

    /**
     * @brief Mutateur : modifie la taille du Serpent2
     */
    void setTaille(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonn�e x du Serpent2
     */
    void setX(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonn�e y du Serpent2
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
     * @brief Mutateur : modifie la coordonn�e x du corps du Serpent2
     */
    void setCorpsX(unsigned int x);

    /**
     * @brief Mutateur : modifie la coordonn�e y du corps du Serpent2
     */
    void setCorpsY(unsigned int y);
};

#endif // Serpent2.h
