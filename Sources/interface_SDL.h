/**
 * \file interface_SDL.h
 * \author Nicolas Symphorien
 * \version 0.0.1
 * \date 18 mai 2012
 *
 * \brief En-tête de la partie interface du programme.
 *
 * En-tête définisant les différentes classes et structures pour la partie interface du programme.
 */

#ifndef INCLUDE_INTERFACE_SDL_H
#define INCLUDE_INTERFACE_SDL_H

#include <fstream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define LARGEUR_FENETRE 640
#define HAUTEUR_FENETRE 480

void lancerInterfaceSDL();

#endif
