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

SDLSimple::SDLSimple () : j() {
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
	dimx = j.getTerrain().getDimX();
	dimy = j.getTerrain().getDimY();
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

    im_serpentHaut.loadFromFile("data/teteHaut.png",renderer);
    im_serpentBas.loadFromFile("data/teteBas.png",renderer);
    im_serpentDroite.loadFromFile("data/teteDroite.png",renderer);
    im_serpentGauche.loadFromFile("data/teteGauche.png",renderer);

    im_serpent2Haut.loadFromFile("data/tete2Haut.png",renderer);
    im_serpent2Bas.loadFromFile("data/tete2Bas.png",renderer);
    im_serpent2Droite.loadFromFile("data/tete2Droite.png",renderer);
    im_serpent2Gauche.loadFromFile("data/tete2Gauche.png",renderer);

    im_mur.loadFromFile("data/mur.png",renderer);

    im_pomme.loadFromFile("data/pomme.png",renderer);
    im_raisin.loadFromFile("data/raisin.png",renderer);
    im_glace.loadFromFile("data/glace.png",renderer);
    im_gpomme.loadFromFile("data/pommeverte.png",renderer);
    im_piment.loadFromFile("data/piment.png",renderer);
    im_pobanana.loadFromFile("data/peaubanane.png",renderer);
    im_pommor.loadFromFile("data/pommor.png",renderer);
    im_corps1.loadFromFile("data/corps.png",renderer);
    im_corps2.loadFromFile("data/corps2.png",renderer);

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

void SDLSimple::sdlAffSOLO() {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	unsigned int x,y;
    Terrain& ter = j.getTerrain();
    Serpent& s = j.getSerpent();
    Fruit& f = j.getFruit();

    // Afficher les sprites des murs
	for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite de serpent
	for(unsigned int i=0;i<s.getTaille(); i++)
    {
        if(s.getDirection()==1) { if(s.getC(i)=='@') { im_serpentHaut.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getDirection()==2) { if(s.getC(i)=='@') { im_serpentGauche.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getDirection()==3) { if(s.getC(i)=='@') { im_serpentBas.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getDirection()==0) { if(s.getC(i)=='@') { im_serpentDroite.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getC(i)=='o') { im_corps1.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
    }

	// Afficher le sprite du Fruit
	if(f.getCharF()=='p') { im_pomme.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='a') { im_piment.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='b') { im_gpomme.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='c') { im_pobanana.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='d') { im_glace.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='8') { im_pommor.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='t') { im_raisin.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
}

void SDLSimple::sdlAffVS() {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	unsigned int x,y;
    Terrain& ter = j.getTerrain();
    Serpent& s = j.getSerpent();
    Serpent2& s2 = j.getSerpent2();
    Fruit& f = j.getFruit();

    // Afficher les sprites des murs
	for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite de serpent
	for(unsigned int i=0;i<s.getTaille(); i++)
    {
        if(s.getDirection()==1) { if(s.getC(i)=='@') { im_serpentHaut.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getDirection()==2) { if(s.getC(i)=='@') { im_serpentGauche.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getDirection()==3) { if(s.getC(i)=='@') { im_serpentBas.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getDirection()==0) { if(s.getC(i)=='@') { im_serpentDroite.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s.getC(i)=='o') { im_corps1.draw(renderer,s.getX(i)*TAILLE_SPRITE,s.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
    }

    // Afficher le sprite de serpent2
	for(unsigned int i=0;i<s2.getTaille(); i++)
    {
        if(s2.getDirection()==1) { if(s2.getC(i)=='X') { im_serpent2Haut.draw(renderer,s2.getX(i)*TAILLE_SPRITE,s2.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s2.getDirection()==2) { if(s2.getC(i)=='X') { im_serpent2Gauche.draw(renderer,s2.getX(i)*TAILLE_SPRITE,s2.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s2.getDirection()==3) { if(s2.getC(i)=='X') { im_serpent2Bas.draw(renderer,s2.getX(i)*TAILLE_SPRITE,s2.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s2.getDirection()==0) { if(s2.getC(i)=='X') { im_serpent2Droite.draw(renderer,s2.getX(i)*TAILLE_SPRITE,s2.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); } }
        if(s2.getC(i)=='+') { im_corps2.draw(renderer,s2.getX(i)*TAILLE_SPRITE,s2.getY(i)*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
    }

	// Afficher le sprite du Fruit
	if(f.getCharF()=='p') { im_pomme.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='a') { im_piment.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='b') { im_gpomme.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='c') { im_pobanana.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='d') { im_glace.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='8') { im_pommor.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }
	if(f.getCharF()=='t') { im_raisin.draw(renderer,f.getX()*TAILLE_SPRITE,f.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE); }


}

void SDLSimple::sdlBoucleSOLO() {

    Terrain& t = j.getTerrain();
    Serpent& s = j.getSerpent();
    Extra& e = j.getExtra();

    SDL_Event events;
	bool quit = j.finPartie();
    Uint32 time = SDL_GetTicks(), nt;
    double t1 = e.getTime1();

	// tant que ce n'est pas la fin ...
	while (quit) {

            nt = SDL_GetTicks();
            unsigned int dir=s.getDirection();
				if (nt-time>(t1*1000))
                {
                    switch (dir)  {
                        case 2:  s.gauche(t,dir);  break;
                        case 0:  s.droite(t,dir);  break;
                        case 1:  s.haut(t,dir);  break;
                        case 3:  s.bas(t,dir);  break;
                    }
                    s.deplacementCorps();
                    quit=j.finPartie();
                    j.choixFruit(1);
                    time = nt;
                }

		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = false;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
			  // bool mangePastille = false;
				switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_UP: j.actionClavier('z'); break;
                    case SDL_SCANCODE_DOWN: j.actionClavier('s'); break;
                    case SDL_SCANCODE_LEFT: j.actionClavier('q'); break;
                    case SDL_SCANCODE_RIGHT: j.actionClavier('d'); break;
                    case SDL_SCANCODE_ESCAPE:
                    case SDL_SCANCODE_Q: quit = true; break;
                    default: break;
				}
				/*if ((withSound) && (mangePastille))
                    Mix_PlayChannel(-1,sound,0);*/
			}
		}

		// on affiche le jeu sur le buffer cach�
		sdlAffSOLO();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}

void SDLSimple::sdlBoucleVS() {

    Terrain& t = j.getTerrain();
    Serpent& s = j.getSerpent();
    Serpent2& s2 = j.getSerpent2();
    Extra& e = j.getExtra();

    SDL_Event events;
	bool quit = j.finPartie();
    Uint32 time = SDL_GetTicks(), nt;
    Uint32 time2 = SDL_GetTicks();
    double t1 = e.getTime1();
    double t2 = e.getTime2();

	// tant que ce n'est pas la fin ...
	while (quit) {

            nt = SDL_GetTicks();
            unsigned int dir=s.getDirection();
            unsigned int dir2=s2.getDirection();

				if (nt-time>(t1*1000))
                {
                    switch (dir)  {
                        case 2:  s.gauche(t,dir);  break;
                        case 0:  s.droite(t,dir);  break;
                        case 1:  s.haut(t,dir);  break;
                        case 3:  s.bas(t,dir);  break;
                    }
                    s.deplacementCorps();
                    quit=j.finPartie();
                    j.choixFruit(j.getPanier());
                    time = nt;
                }
                if (nt-time2>(t2*1000))
                {
                    switch (dir2)  {
                        case 2:  s2.gauche(t,dir2);  break;
                        case 0:  s2.droite(t,dir2);  break;
                        case 1:  s2.haut(t,dir2);  break;
                        case 3:  s2.bas(t,dir2);  break;
                    }
                    s2.deplacementCorps();
                    quit=j.finPartie();
                    j.choixFruit(1); //j.choixFruit(j.getPanier());
                    time2 = nt;
                }

		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = false;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
				switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_UP: j.actionClavier('z'); break;
                    case SDL_SCANCODE_DOWN: j.actionClavier('s'); break;
                    case SDL_SCANCODE_LEFT: j.actionClavier('q'); break;
                    case SDL_SCANCODE_RIGHT: j.actionClavier('d'); break;
                    case SDL_SCANCODE_W: j.actionClavier('o'); break;
                    case SDL_SCANCODE_S: j.actionClavier('l'); break;
                    case SDL_SCANCODE_A: j.actionClavier('k'); break;
                    case SDL_SCANCODE_D: j.actionClavier('m'); break;
                    case SDL_SCANCODE_ESCAPE: quit = true; break;
                    default: break;
				}
				/*if ((withSound) && (mangePastille))
                    Mix_PlayChannel(-1,sound,0);*/
			}
		}

		// on affiche le jeu sur le buffer cach�
		sdlAffVS();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}


