#ifndef _SERPENT_H
#define _SERPENT_H

const int MAX = 200;

/// Structure MorceauS
struct MorceauS
{
    /// Charactere representant le serpent
    char c;
    /// Coordonnées du morceau de serpent
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
     * @brief Constructeur par défaut de la classe:
       Initialise les variables du serpent ( Coordonnée de la tete, la taille du serpent, sa direction de base, le charactere representant la tete, la vie bonus à 0, ...)
     */
    Serpent();

    /**
     * @brief Procedure qui deplace le serpent à droite.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent d'une case vers la droite.
       @param dir : entié superieur ou egal à 0
     */
    void droite(unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent à haut.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent d'une case vers la haut.
       @param dir : entié superieur ou egal à 0
     */
    void haut(unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent à gauche.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent d'une case vers la gauche.
       @param dir : entié superieur ou egal à 0
     */
    void gauche(unsigned int dir);

    /**
     * @brief Procedure qui deplace le serpent à bas.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du serpent d'une case vers la bas.
       @param dir : entié superieur ou egal à 0
     */
    void bas(unsigned int dir);

    /**
     * @brief Procedure qui ajoute un corps au serpent.
       La Procedure permet de quand elle est appelée d'ajouter un corps au serpent.
     */
    void ajouterCorps();

    /**
     * @brief Procedure qui deplace le corps du serpent.
       La Procedure permet de quand elle est appelée de deplacer chaque membre du corps du serpent à la case anciennement occupé par un membre du serpent.
     */
    void deplacementCorps();

    /**
     * @brief Fonction qui test les collisions du serpent.
       La Fonction qui test si le serpent rentre dans son corps à partir d'une taille egal à 5 (taille à partir de laquelle le serpent peut rentrer dans son corps.
       @return true si collision sinon false
     */
    bool collisionS();

    /**
     * @brief Accesseur : récupère la taille du serpent
     */
    unsigned int getTaille();

    /**
     * @brief Accesseur : récupère la coordonnée x du morceau choisie
       @param rang : entié superieur ou egal à 0 qui represente le rang du morceau du serpent choisie dans le tableau
     */
    unsigned int getX(unsigned int rang) const;

    /**
     * @brief Accesseur : récupère la coordonnée y du morceau choisie
       @param rang : entié superieur ou egal à 0 qui represente le rang du morceau du serpent choisie dans le tableau
     */
    unsigned int getY(unsigned int rang) const;

    /**
     * @brief Accesseur : récupère le charactere c du morceau choisie
       @param rang : entié superieur ou egal à 0 qui represente le rang du morceau du serpent choisie dans le tableau
     */
    char getC(unsigned int rang) const;

    /**
     * @brief Accesseur : récupère la direction du serpent
     */
    unsigned int getDirection() const;

    /**
     * @brief Accesseur : récupère le booleen indiquant si le serpent à une vie ou non
     */
    bool getVie() const ;

    /**
     * @brief Mutateur : modifie la taille du Serpent
     */
    void setTaille(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonnée x du Serpent
     */
    void setX(unsigned int a);

    /**
     * @brief Mutateur : modifie la coordonnée y du Serpent
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
     * @brief Mutateur : modifie la coordonnée x du corps du Serpent
     */
    void setCorpsX(unsigned int x);

    /**
     * @brief Mutateur : modifie la coordonnée y du corps du Serpent
     */
    void setCorpsY(unsigned int y);

    /**
     * @brief Procedure qui teste le fonctionnement du code.
       Permet de tester qu'à chaque fois que le logiciel est modifié, que les choses qui fonctionnaient avant fonctionnent toujours.
     */
    void STestRegression();

};

#endif // Serpent.h
