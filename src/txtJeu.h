#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "Jeu.h"

/**
 * @brief Procedure pour la boucle du mode SOLO ( et arcade ) en mode texte
   La procedure permet de faire tourner le mode solo dans une boucle qui ne se fini pas tant que le serpent ne meurt pas
   elle permet egalement le deplacement du serpent grace à une boucle temporelle ainsi que l'affichage des elemnts qui compose le jeu.
   Cette procedure prend en main tous le jeu en appelant les fonctions necessaire.
   @param Jeu : la classe Jeu
 */
void txtBoucleSOLO(Jeu & j);

/**
 * @brief Procedure pour la boucle du mode VS ( et Vs IA ) en mode texte
   La procedure permet de faire tourner le mode vs dans une boucle qui ne se fini pas tant que le serpent ne meurt pas
   elle permet egalement le deplacement du serpent grace à une boucle temporelle ainsi que l'affichage des elemnts qui compose le jeu.
   Cette procedure prend en main tous le jeu en appelant les fonctions necessaire.
   @param Jeu : la classe Jeu
 */
void txtBoucleVS(Jeu & j);

/**
 * @brief Procedure pour choisir le mode de jeu en mode texte
   On demande à l'utilisateur de choisir le mode de jeu souhaité.
   En fonction du choix du joueur appelle les diffenrentes boucle en fonction du mode de jeu choisie
   @param Jeu : la classe Jeu
 */
void menu(Jeu & j);

#endif
