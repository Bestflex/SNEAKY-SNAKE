#ifndef _TERRAIN_H
#define _TERRAIN_H


/// Classe qui gere le terrain
class Terrain{

private:
    /// Dimension x du terrain
    unsigned int dimx;
	/// Dimension y du terrain
	unsigned int dimy;
	/// Choix du terrain
	unsigned int choixT;
	/// Tableau 2d pour le terrain
	char ter[100][100];

public:

    /**
     * @brief Constructeur par d�faut de la classe:
       Initialise les dimension du terrain et choisie un terrain aleatoirement parmi 4 terrains
     */
    Terrain();

    /**
     * @brief Fonction qui test les collision avec les murs.
       La Fonction qui test si les serpents rentre dans le mur.
       @param x : enti� superieur ou egal � 0 (coordonn�e x saisie)
       @param y : enti� superieur ou egal � 0 (coordonn�e y saisie)
       @return true si collision sinon false
     */
    bool collisionT(unsigned int x,unsigned int y) const;

    /**
     * @brief Fonction qui test la collision avec le teleporteur1.
       La Fonction qui test si les serpents rentre dans le teleporteur1.
       @param x : enti� superieur ou egal � 0 (coordonn�e x saisie)
       @param y : enti� superieur ou egal � 0 (coordonn�e y saisie)
       @return true si collision sinon false
     */
    bool collisionTeleporteur1(unsigned int x,unsigned int y) const;

    /**
     * @brief Fonction qui test la collision avec le teleporteur2.
       La Fonction qui test si les serpents rentre dans le teleporteur2.
       @param x : enti� superieur ou egal � 0 (coordonn�e x saisie)
       @param y : enti� superieur ou egal � 0 (coordonn�e y saisie)
       @return true si collision sinon false
     */
    bool collisionTeleporteur2(unsigned int x,unsigned int y) const;

    /**
     * @brief Accesseur : r�cup�re le charactere ayant pour coordonn�es x et y dans le terrain
       @param x : enti� superieur ou egal � 0 (coordonn�e x saisie)
       @param y : enti� superieur ou egal � 0 (coordonn�e y saisie)
     */
    char getXY(unsigned int x,unsigned int y)const;

    /**
     * @brief Accesseur : r�cup�re la coordonn�e x du terrain
     */
    unsigned int getDimX() const;

    /**
     * @brief Accesseur : r�cup�re la coordonn�e y du terrain
     */
    unsigned int getDimY() const;

};

#endif
