/**
 * \file main.cpp
 * \author Nicolas Symphorien
 * \version 0.0.1
 * \date 16 mai 2012
 *
 * \brief Fichier "main" du programme.
 *
 * Fichier main du progamme permettant de tester les différentes structures définie dans "core.h".
 */

#include <iostream>
#include <iomanip>

#include "core.h"
#include "interface_SDL.h"

using namespace std;

int main()
{
	// Test des methodes
	
	cout << "TEST DES METHODES UNIQUEMENT" << endl << endl;

	Environnement testEnv;

	cout << "L'environnement \"testEnv\" a pour taille : (" << testEnv.tailleEnX() << ";" << testEnv.tailleEnY() << ")." << endl;
	
	Environnement testEnv2(5, 5);
	
	cout << "L'environnement \"testEnv2\" a pour taille : (" << testEnv.tailleEnX() << ";" << testEnv.tailleEnY() << ")." << endl;
	
	Almanach almanachForet;
	almanachForet[1] = "Arbre";
	almanachForet[2] = "Herbe";
	
	Entite testEntite;
	cout << "L'entite \"testEntite\" a pour nom : " << testEntite.obtenirNom(almanachForet) << "." << endl;
	
	testEnv2.insererEntite(0, 0, testEntite);
	cout << "Insertion de l'entite \"testEntite\" dans l'environnement \"testEnv2\" a la position (0;0)." << endl;
	Entite testEntite2(1);
	testEnv2.insererEntite(1, 0, testEntite2);
	cout << "Insertion de l'entite \"testEntite2\" dans l'environnement \"testEnv2\" a la position (1;0)." << endl;

	cout << "Affichage console de l'environnement \"testEnv2\" :" << endl;
	for (int j = 0 ; j < testEnv2.tailleEnX() ; j++)
	{
		cout << " ";
		for (int i = 0 ; i < testEnv2.tailleEnY() ; i++)
		{
			cout << setw(5) << setfill('.') << testEnv2.extraireEntite(i, j).obtenirNom(almanachForet) << " " ;
		}
		cout << endl;
	}

	// Test des surcharges d'operateurs
	
	cout << endl << "TEST DES SURCHAGES" << endl << endl;
	
	Environnement foret(8, 5);
	cout << "Création de l'environnement foret..." << endl;
	
	Entite arbre(1);
	Entite herbe(2);
	cout << "Création des entités arbre et herbe..." << endl;

	foret(0,0) = herbe;
	foret(1,2) = arbre;
	foret(1,1) = arbre;
	cout << "Chargement des entités arbre et herbe dans l'environnement foret" << endl;
	
	cout << "Affichage console de l'environnement \"foret\" :" << endl;
	for (int j = 0 ; j < foret.tailleEnX() ; j++)
	{
		cout << " ";
		for (int i = 0 ; i < foret.tailleEnY() ; i++)
		{
			cout << setw(5) << setfill('.') << left << foret(i,j).obtenirNom(almanachForet) << " " ;
		}
		cout << endl << right ;
	}

	// Test interface SDL
	
	lancerInterfaceSDL();
	
	return 0;
}
