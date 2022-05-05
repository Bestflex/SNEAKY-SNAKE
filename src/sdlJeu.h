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



/**
    La classe gerant le jeu avec un affichage SDL
*/
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

    Image im_pomme;
    Image im_raisin;
    Image im_glace;
    Image im_gpomme;
    Image im_piment;
    Image im_pobanana;
    Image im_pommor;




    bool souris;
    bool touche;
public :

    SDLSimple();
    ~SDLSimple();
    void sdlAffSOLO();
    void sdlAffVS();
    void sdlBoucleSOLO();
    void sdlBoucleVS();


};

#endif
