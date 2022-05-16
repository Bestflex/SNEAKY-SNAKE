# Projet LIFAP4 : SNEAKY SNAKE      BENAZIZ Oussama p2007990 ; VOIRIN Camille p1919874      git url : https://forge.univ-lyon1.fr/p2007990/sneaky-snake.git

/!\ La version Texte ne marche pas sur linux (impossible de trouver le probleme), on a verifier avec un professeur qui nous demander de faire un projet codeblocks pour la demo /!\

Le projet SNEAKY SNAKE est la reproduction du celebre jeu snake reproduit à notre image, il est composé de quatre mode de jeu (mode basique, mode arcade, mode arcade VS, mode arcade VS IA).
Le jeu possede deux versions, une version texte (representé par des characteres) et une version sdl (avec des images).

Pour la version texte :
Lorsque le jeu est en mode solo (mode basique, mode arcade) le serpent se deplace avec les touches ZQSD.
Lorsque le jeu est en mode VS (mode arcade VS, mode arcade VS IA) le serpent1 (vert) se deplace avec les touches ZQSD et le serpent2 avec les touches OKLM.

Pour la version SDL :
Lorsque le jeu est en mode solo (mode basique, mode arcade) le serpent se deplace avec les fleches du clavier.
Lorsque le jeu est en mode VS (mode arcade VS, mode arcade VS IA) le serpent1 (vert) se deplace avec les fleches du clavier et le serpent2 avec les touches ZQSD.


## L'organistion des fichiers est la suivante :

- **bin**        : Les fichiers executable crées avec la commande make depuis ../bin , pour ouvrir un fichier il faut executer la commande ./bin/nom_executable , exemple : ./bin/main_sdl. 
- **data**       : Contient les images utilisées dans le code.
- **doc**        : Contient le fichier .doxy (permettant d'éditer et générer la documentation doxygen) et les autre document (diagramme des classes, diagramme de gantt, Pdf projet oral). 
- **obj**        : répertoire comportant les fichiers objets créés lors de la compilation.
- **src**        : Contient les fichiers source .cpp et .h permettant de compiler le programme.
- **Makefile**   : Permet d'executer une implémentation d'un module image.
- **README.md**  : ce readme

### Pour compiler :

- Préambule : si vous voulez un Linux sous Windows, vous pouvez installer WSL ! 
  Voir la page de l'UE : https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows

- Pour installer SDL2
  Pour installer SDL2 sous Linux ou avec WSL/Windows
  ``` sudo apt install python3 valgrind doxygen libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick ```

- Une fois SDL2 et WSL installés, la compilation s'effectue en ligne de commande:
  Depuis le répertoire racine du module image, exécutez la commande make.
  Puis ouvrez les fichiers executable crees dans ../bin :
  - ./bin/test       : Appelle au test de regression
  - ./bin/main_txt    : Affiche le jeu en version texte
  - ./bin/main_sdl  : Affiche le jeu en version graphique

#### Details annexe sur le programme :

Le programme contient huit classes et utilise plusieurs librairies.
Les librairies utilisés sont : <stdlib.h> <time.h> <iostream> <SDL.h> <SDL_image.h> <SDL_mixer.h> <string> <cassert> <fstream> <chrono> <unistd.h> <windows.h>

- class Extra :
  La class Extra permet de gerer les scores ainsi que les temps utilisé pour les vitesses des serpents. 

- class Fruit
  La class Fruit permet d'initialiser les fruit avec un charactere et une position, elle permet egalement de leur accorder un effet qui agira sur les serpents.
  Elle choisie egalement quelle type de fruit afficher selon les modes de jeux.

- class Serpent/Serpent2
  La class Serpent( et Serpent2 ) permet d'initialiser un serpent avec une taille une position. Elle gere egalement les deplacements du serpent et de son corps ainsi que les collisions du serpent.

- class Terrain
  La class Terrain permet de gerer les terrains qui sont au nombres de quatre ainsi que les collision avec les partie du terrain.

- class Jeu
  La class Jeu permet de gerer le jeu en definissant les touches qui feront deplacé les serpents, ce qui se passe quand le serpent mange le fruit, les collision entre serpent, les deplacement de l'IA et sa maniere d'agire
  les conditions de fin de partie.

- class txtJeu
  La class txtJeu permet d'afficher et faire tourner le jeu dans un boucle tant que les conditions de fin de jeu ne sont pas respecté, elle permet de faire deplacer les serpent grace a des 
  boucles temporelles et appelle les fonction necessaire au jeu. Elle gere egalement le menu en version texte.

- class sldJeu
  La class sldJeu permet d'afficher et faire tourner le jeu dans un boucle tant que les conditions de fin de jeu ne sont pas respecté, elle permet de faire deplacer les serpent grace a des 
  boucles temporelles et appelle les fonction necessaire au jeu. Elle gere le menu en version sdl et permet egalement la gestion et l'affichage des images qui sont utilisé pour afficher le jeu.

##### Regle du jeu :

Une fois le jeu lancé (grace à .bin/main_txt) vous vous retrouvez face à un menu ou vous devez choisir le mode de jeu souhaiter.
- Le mode basique est la representation classique du jeu snack (avce seulement le fruit de base)
- Le mode Arcade est le meme jeu avec des fruits qui accorde des bonus et malus differents
- Le mode Arcade VS est le jeu en mode arcade contre un autre joueur
- Le mode Arcade VS IA est le jeu en mode arcade contre IA

Une fois le mode de jeu choisie un terrain est choisie aleatoirement parmis quatre terrains present dans le jeu. Le but du jeu est de survivre le plus longtemps possible tous en ayant 
le meilleur score.

En fonction du mode choisie vous aurez differents fruit à disposition : 
- Pour le mode basique : - p (pomme rouge) : augmente la taille du serpent et le score 

- Pour les modes arcades : - p (pomme rouge) : augmente la taille du serpent et le score (peut egalement reinitialiser la vitesse du serpent si elle est changer)
                           - b (pomme verte) : augmente la taille du serpent et le score de 2
                           - 8 (pomme dorée) : donne une vie au serpent l'empechant de mourir
                           - c (peau de banane) : reduit la taile du serpent et augmente le score (Attention : si le serpent possede que la tete ce fruit le tue)
                           - a (pimment) : augmente la taille du serpent et le score ainsi que sa vitesse
                           - d (glace) : augmente la taille du serpent, le score et diminue la vitesse du serpent
                           - t (raisin) : augmente la taille du serpent, le score et le teleporte à une position aleatoire dans le terrain

Dans un certain terrain "spaciale" vous pourrez tombé sur des teleporteur qui peuvent vous faire passer d'une zonne à l'autre 0/O (trou noir)

Les terrains :

        Terrain 1                            Terrain 2                          Terrain 3                    Terrain 4 (spaciale)
#############################      #############################      #############################      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#                           #      #                           #      #         ##                #      ~                          O~
#                           #      #                     ##### #      #            #####    ###   #      ~                           ~
#                           #      #    #                  #   #      #       ##                  #      ~~~~~~~~~~~~~~~~~~~~~~~~    ~
#                           #      #     #                 #   #      ###        #######          #      ~             ~             ~
#                           #      #      #                 #  #      #                   #       #      ~             ~             ~
#                           #      #       ######              #      # #        #######   #   ####      ~     ~~~~~~~~~~~~~~~~~~~~~~~
#                           #      #         #            #    #      #  #    #                   #      ~                           ~
#                           #      #                           #      #          #######          #      ~                          0~
#############################      #############################      #############################      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Une fois la partie fini fermer et relancer l'executable pour pouvoir rejouer.



