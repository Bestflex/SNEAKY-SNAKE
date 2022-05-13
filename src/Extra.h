#ifndef _EXTRA_H
#define _EXTRA_H
/// Classe qui gere les temps et les scores
class Extra{

private:

    /// Temps pour vitesse du premier Serpent
    double time1;
    /// Temps pour vitesse du deuxieme Serpent (Serpent2)
    double time2;
    /// Score du premier Serpent
    unsigned int score1;
    /// Score du deuxieme Serpent (Serpent2)
    unsigned int score2;

public:

    /**
     * @brief Constructeur par défaut de la classe:
       Initialise les variables correspondants à la vitesse des deux serpents ainsi que le score des deux joueurs
     */
    Extra();

    /**
     * @brief Accesseur : récupère le temps du premier Serpent
     */
     double getTime1() const;

    /**
     * @brief Accesseur : récupère le temps du deuxieme Serpent
     */
    double getTime2() const;

    /**
     * @brief Accesseur : récupère le score du premier Serpent
     */
    unsigned int getScore1() const;

    /**
     * @brief Accesseur : récupère le score du deuxieme Serpent
     */
    unsigned int getScore2() const;

    /**
     * @brief Mutateur : modifie le temps du premier Serpent
     */
    void setTime1(double a);

    /**
     * @brief Mutateur : modifie le temps du deuxieme Serpent
     */
    void setTime2(double a);

    /**
     * @brief Mutateur : modifie le score du premier Serpent
     */
    void setScore1(unsigned int a);

    /**
     * @brief Mutateur : modifie le score du deuxieme Serpent
     */
    void setScore2(unsigned int a);
};

#endif // Extra.h
