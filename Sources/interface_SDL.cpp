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

#include <iostream>

#include "interface_SDL.h"


bool sourieSurSurface(const SDL_Rect positionSourie, SDL_Surface *surface, const SDL_Rect positionSurface);
void gestionMenu(const SDL_Rect & positionSourie, SDL_Surface *ecran);

using namespace std;

void lancerInterfaceSDL()
{
	SDL_Init(SDL_INIT_VIDEO); // TODO Gestion erreurs SDL
	TTF_Init();

	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE); // TODO Gestion erreurs SDL
	
	SDL_Rect positionFond;
	SDL_Surface *imageDeFond = NULL;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

	imageDeFond = IMG_Load("test.png");
	positionFond.x = (LARGEUR_FENETRE / 2) - (imageDeFond->w / 2);
	positionFond.y = 0;
	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

	TTF_Font *policeMenu = NULL;
	policeMenu = TTF_OpenFont("Sketch_Block.ttf", 80);
	SDL_Surface *nomProg = NULL;
	SDL_Color couleur = {0, 0, 0};
	nomProg = TTF_RenderText_Blended(policeMenu, "NewUniverse", couleur);
	SDL_Rect positionTexte;
	positionTexte.x = (LARGEUR_FENETRE / 2) - (nomProg->w / 2);
	positionTexte.y = 30;
	SDL_BlitSurface(nomProg, NULL, ecran, &positionTexte);

	SDL_Flip(ecran);
	
	SDL_Event evenement;
	SDL_Rect positionSourie;
	bool boucleEvenementActive = true;
	while(boucleEvenementActive)
	{
		SDL_WaitEvent(&evenement);
		switch(evenement.type)
		{
			case SDL_MOUSEMOTION :
				positionSourie.x = evenement.motion.x;
				positionSourie.y = evenement.motion.y;
				break;
			case SDL_MOUSEBUTTONUP:
				break;
			case SDL_QUIT :
				boucleEvenementActive = false;
				break;
		}
		
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(nomProg, NULL, ecran, &positionTexte);
		gestionMenu(positionSourie, ecran);
		SDL_Flip(ecran);
	}
		

	SDL_Quit();
}

bool sourieSurSurface(const SDL_Rect positionSourie, SDL_Surface *surface, const SDL_Rect positionSurface)
{
	if((positionSourie.x >= positionSurface.x && positionSourie.x <= positionSurface.x + surface->w) && (positionSourie.y >= positionSurface.y && positionSourie.y <= positionSurface.y + surface->h))
		return true;
	else
		return false;
}

void gestionMenu(const SDL_Rect & positionSourie, SDL_Surface *ecran)
{
	SDL_Surface *txtMenu_lancer = NULL, *txtMenu_options = NULL, *txtMenu_quitter = NULL;

	SDL_Rect positionTxtMenu;
	positionTxtMenu.x = 380;
	positionTxtMenu.y = 200;

	SDL_Color couleurNoir = {0, 0, 0}, couleurGris = {50, 50, 50};

	TTF_Font *policeMenu = NULL;
	policeMenu = TTF_OpenFont("Sketch_Block.ttf", 60);
	
	txtMenu_lancer = TTF_RenderText_Blended(policeMenu, "Lancer", couleurNoir);
	txtMenu_options = TTF_RenderText_Blended(policeMenu, "Options", couleurNoir);
	txtMenu_quitter = TTF_RenderText_Blended(policeMenu, "Quitter", couleurNoir);
	
	bool etatCourant; // Variable permettant de ne pas blitté 2 fois la même surface
	if(sourieSurSurface(positionSourie, txtMenu_lancer, positionTxtMenu) && etatCourant == 0)
	{
		txtMenu_lancer = TTF_RenderText_Blended(policeMenu, "Lancer", couleurNoir);
		SDL_BlitSurface(txtMenu_lancer, NULL, ecran, &positionTxtMenu);
		etatCourant = 1;
	}
	else
	{
		txtMenu_lancer = TTF_RenderText_Blended(policeMenu, "Lancer", couleurGris);
		SDL_BlitSurface(txtMenu_lancer, NULL, ecran, &positionTxtMenu);
		etatCourant = 0;
	}

	positionTxtMenu.y += 60;
	if(sourieSurSurface(positionSourie, txtMenu_options, positionTxtMenu) && etatCourant == 0)
	{
		txtMenu_options = TTF_RenderText_Blended(policeMenu, "Options", couleurNoir);
		SDL_BlitSurface(txtMenu_options, NULL, ecran, &positionTxtMenu);
		etatCourant = 1;
	}
	else
	{
		txtMenu_options = TTF_RenderText_Blended(policeMenu, "Options", couleurGris);
		SDL_BlitSurface(txtMenu_options, NULL, ecran, &positionTxtMenu);
		etatCourant = 0;
	}

	positionTxtMenu.y += 60;
	if(sourieSurSurface(positionSourie, txtMenu_quitter, positionTxtMenu) && etatCourant == 0)
	{
		txtMenu_quitter = TTF_RenderText_Blended(policeMenu, "Quitter", couleurNoir);
		SDL_BlitSurface(txtMenu_quitter, NULL, ecran, &positionTxtMenu);
		etatCourant = 1;
	}
	else
	{
		txtMenu_quitter = TTF_RenderText_Blended(policeMenu, "Quitter", couleurGris);
		SDL_BlitSurface(txtMenu_quitter, NULL, ecran, &positionTxtMenu);
		etatCourant = 0;
	}

	SDL_FreeSurface(txtMenu_lancer);
	SDL_FreeSurface(txtMenu_options);
	SDL_FreeSurface(txtMenu_quitter);
	TTF_CloseFont(policeMenu);
}

	
