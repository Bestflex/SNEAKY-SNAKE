#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Jeu.h"

//! \brief Pour g�rer une image avec SDL2
class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;

public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

///La classe gerant le jeu avec un affichage SDL
class SDLSimple {

private :

	Jeu j;

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;

    Image im_menu;
    Image im_legende;

    Image im_serpentHaut;
    Image im_serpentBas;
    Image im_serpentDroite;
    Image im_serpentGauche;

    Image im_serpent2Haut;
    Image im_serpent2Bas;
    Image im_serpent2Droite;
    Image im_serpent2Gauche;

    Image im_corps1;
    Image im_corps2;

    Image im_mur;
    Image im_mur2;

    Image im_pomme;
    Image im_raisin;
    Image im_glace;
    Image im_gpomme;
    Image im_piment;
    Image im_pobanana;
    Image im_pommor;
    Image im_teleporteur;

    bool souris;
    bool touche;
public :

    /**
     * @brief Constructeur par défaut de la classe:
       Initialise toute les variables tel que les images, la musique ...
     */
    SDLSimple();

    /**
     * @brief Destructeur  de la classe:
       Reinitialise (detruit) toute les variables tel que les images, la musique ...
     */
    ~SDLSimple();

    /**
     * @brief Procedure qui Affiche le mode solo.
       La Procedure permet d'afficher tous ce qui est necessaire au mode solo grace a la fonction draw,...
     */
    void sdlAffSOLO();

    /**
     * @brief Procedure qui Affiche le mode VS.
       La Procedure permet d'afficher tous ce qui est necessaire au mode vs grace a la fonction draw,...
     */
    void sdlAffVS();

    /**
     * @brief Procedure pour la boucle du mode SOLO ( et arcade ) en mode SDL
     La procedure permet de faire tourner le mode solo dans une boucle qui ne se fini pas tant que le serpent ne meurt pas
     elle permet egalement le deplacement du serpent grace à une boucle temporelle ainsi que l'affichage des elemnts qui compose le jeu.
     Cette procedure prend en main tous le jeu en appelant les fonctions necessaire.
     */
    void sdlBoucleSOLO();

    /**
     * @brief Procedure pour la boucle du mode VS ( et Vs IA ) en mode SDL
     La procedure permet de faire tourner le mode vs dans une boucle qui ne se fini pas tant que le serpent ne meurt pas
     elle permet egalement le deplacement du serpent grace à une boucle temporelle ainsi que l'affichage des elemnts qui compose le jeu.
     Cette procedure prend en main tous le jeu en appelant les fonctions necessaire.
     */
    void sdlBoucleVS();

    /**
     * @brief Procedure pour choisir le mode de jeu en mode SDL
     On affiche une image de menu à l'utilisateur et en fonction de la position du click de sa souris
     on appelle les diffenrentes boucles.
     */
    void Menu();

};

#endif
