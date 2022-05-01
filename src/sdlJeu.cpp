#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}










// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple () : jeu() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

	int dimx, dimy;
	dimx = jeu.getTerrain().getDimX();
	dimy = jeu.getTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("SNEAKY SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_serpent.loadFromFile("data/tete.png",renderer);
    im_serpent2.loadFromFile("data/tete2.png",renderer);

    im_mur.loadFromFile("data/mur.png",renderer);

    im_pomme.loadFromFile("data/pomme.png",renderer);
    im_raisin.loadFromFile("data/raisin.png",renderer);
    im_glace.loadFromFile("data/glace.png",renderer);
    im_gpomme.loadFromFile("data/pommeverte.png",renderer);
    im_piment.loadFromFile("data/piment.png",renderer);
    im_pobanana.loadFromFile("data/peaubanane.png",renderer);
    im_pommor.loadFromFile("data/pommor.png",renderer);



    // FONTS
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
            SDL_Quit();
            exit(1);
	}
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"SNEAKY SNAKE",font_color));
	font_im.loadFromCurrentSurface(renderer);

    // SONS
    /*if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr)
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }
    }*/
}

SDLSimple::~SDLSimple () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLSimple::sdlAff () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	unsigned int x,y;
    Terrain& ter = jeu.getTerrain();
    Serpent& s = jeu.getSerpent();
    Serpent2& s2 = jeu.getSerpent2();
    Fruit& f = jeu.getFruit();

    // Afficher les sprites des murs et des pastilles
	for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite de serpent
	im_serpent.draw(renderer,s.getX(0)*TAILLE_SPRITE,s.getY(0)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite du Fantome
	im_serpent2.draw(renderer,s2.getX(0)*TAILLE_SPRITE,s2.getY(0)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite du Fruit
	if(f.getCharF()=='p') { im_pomme.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='a') { im_piment.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='b') { im_gpomme.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='c') { im_pobanana.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='d') { im_glace.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='8') { im_pommor.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='t') { im_raisin.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }


}

void SDLSimple::sdlBoucle () {

    Terrain& t = jeu.getTerrain();
    Serpent& s = jeu.getSerpent();
    Serpent2& s2 = jeu.getSerpent2();
    Fruit& f = jeu.getFruit();

    SDL_Event events;
	bool quit = false;

    Uint32 time = SDL_GetTicks(), nt;

    unsigned int a=s.getDirection();

	// tant que ce n'est pas la fin ...
	while (!quit) {

        nt = SDL_GetTicks();

		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
			  // bool mangePastille = false;
				switch (events.key.keysym.scancode) {
				case SDL_SCANCODE_UP:
				  jeu.actionClavier('z');
					break;
				case SDL_SCANCODE_DOWN:
				  jeu.actionClavier('s');//	mangePastille = jeu.actionClavier('h');     // car Y inverse
					break;
				case SDL_SCANCODE_LEFT:
				  jeu.actionClavier('q');//	mangePastille = jeu.actionClavier('g');
					break;
				case SDL_SCANCODE_RIGHT:
				  jeu.actionClavier('d');//	mangePastille = jeu.actionClavier('d');
					break;
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
				default: break;
				}
				if (nt-time>500)
                {
                    switch (a)  {
                        case 2:  s.gauche(t,a);  break;
                        case 0:  s.droite(t,a);  break;
                        case 1:  s.haut(t,a);  break;
                        case 3:  s.bas(t,a);  break;
                    }
                    time = nt;
                }
				/*if ((withSound) && (mangePastille))
                    Mix_PlayChannel(-1,sound,0);*/
			}
		}

		// on affiche le jeu sur le buffer cach�
		sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}
