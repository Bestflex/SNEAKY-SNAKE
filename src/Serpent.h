#ifndef _SERPENT_H
#define _SERPENT_H

const int MAX = 200;

/// Structure MorceauS
struct MorceauS
{
    /// Charactere representant le serpent
    char c;
    /// Coordonn�es du morceau de serpent
    unsigned int x,y;
};

/// Classe qui gere le premier Serpent
class Serpent{
private:

    /// Tableau de Morceau de serpent
    MorceauS tab[MAX];
    /// Taille du serpent
    unsigned int taille;
    /// Direction du serpent
    unsigned int direction;
    /// Vie du serpent
    bool vie;

public :

    /**
     * @brief Constructeur par d�faut de la classe:
       Initialise les variables du serpent ( Coordonn�e de la tete, la taille du serpent, sa direction de base, le charactere representant la tete, la vie bonus � 0, ...)
     */
    Serpent();

    /**
     * @brief Procedure qui deplace le serpent � droite.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent d'une case vers la droite.
       @param dir : enti� superieur ou egal � 0
     */
    void droite(unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent � haut.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent d'une case vers la haut.
       @param dir : enti� superieur ou egal � 0
     */
    void haut(unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent � gauche.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent d'une case vers la gauche.
       @param dir : enti� superieur ou egal � 0
     */
    void gauche(unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent � bas.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du serpent d'une case vers la bas.
       @param dir : enti� superieur ou egal � 0
     */
    void bas(unsigned int dir);

    /**
     * @brief Procedure qui ajoute un corps au serpent.
       La Procedure permet de quand elle est appel�e d'ajouter un corps au serpent.
     */
    void ajouterCorps();

    /**
     * @brief Procedure qui deplace le corps du serpent.
       La Procedure permet de quand elle est appel�e de deplacer chaque membre du corps du serpent � la case anciennement occup� par un membre du serpent.
     */
    void deplacementCorps();

    /**
     * @brief Fonction qui test les collisions du serpent.
       La Fonction qui test si le serpent rentre dans son corps � partir d'une taille egal � 5 (taille � partir de laquelle le serpent peut rentrer dans son corps.
       @return true si collision sinon false
     */
    bool collisionS();

    /**
     * @brief Accesseur : r�cup�re la taille du serpent
     */
    unsigned int getTaille();

    /**
     * @brief Accesseur : r�cup�re la coordonn�e x du morceau choisie
       @param rang : enti� superieur ou egal � 0 qui represente le rang du morceau du serpent choisie dans le tableau
     */
    unsigned int getX(unsigned int rang) const;

    /**
     * @brief Accesseur : r�cup�re la coordonn�e y du morceau choisie
       @param rang : enti� superieur ou egal � 0 qui represente le rang du morceau du serpent choisie dans le tableau
     */
    unsigned int getY(unsigned int rang) const;

    /**
     * @brief Accesseur : r�cup�re le charactere c du morceau choisie
       @param rang : enti� superieur ou egal � 0 qui represente le rang du morceau du serpent choisie dans le tableau
     */
    char getC(unsigned int rang) const;

    /**
     * @brief Accesseur : r�cup�re la direction du serpent
     */
    unsigned int getDirection() const;

    /**
     * @brief Accesseur : r�cup�re le booleen indiquant si le serpent � une vie ou non
     */
    bool getVie() const ;

    /**
     * @brief Mutateur : modifie la taille du Serpent
     */
    void setTaille(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonn�e x du Serpent
     */
    void setX(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonn�e y du Serpent
     */
    void setY(unsigned int a);

    /**
     * @brief Mutateur : modifie la direction du Serpent
     */
    void setDirection(unsigned int dir);

    /**
     * @brief Mutateur : modifie le bool representant la vie du Serpent
     */
    void setVie(bool x);

    /**
     * @brief Mutateur : modifie la coordonn�e x du corps du Serpent
     */
    void setCorpsX(unsigned int x);

    /**
     * @brief Mutateur : modifie la coordonn�e y du corps du Serpent
     */
    void setCorpsY(unsigned int y);

    /**
     * @brief Procedure qui teste le fonctionnement du code.
       Permet de tester qu'� chaque fois que le logiciel est modifi�, que les choses qui fonctionnaient avant fonctionnent toujours.
     */
    void STestRegression();

};

#endif // Serpent.h
