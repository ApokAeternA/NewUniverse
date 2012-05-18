/**
 * \file interface_SDL.cpp
 * \author Nicolas Symphorien
 * \version 0.0.1
 * \date 18 mai 2012
 *
 * \brief Définitions de la partie interface du progamme.
 *
 * Définitions des méthodes des classes de la partie interface du programme.
 */

#include "interface_SDL.h"

using namespace std;

void lancerInterfaceSDL()
{
	SDL_Init(SDL_INIT_VIDEO); // TODO Gestion erreurs SDL

	SDL_Surface *ecran;
	SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_SWSURFACE); // TODO Gestion erreurs SDL
	

	SDL_Event evenement;
	bool boucleEvenementActive = true;
	while(boucleEvenementActive)
	{
		SDL_WaitEvent(&evenement);
		switch(evenement.type)
		{
			case SDL_QUIT :
				boucleEvenementActive = false;
				break;
		}
	}

	SDL_Quit();
}
