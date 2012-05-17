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
#include <iostream>

#include "core.h"

using namespace std;

int main()
{
	Environnement testEnv;
	CoupleEntiers taille;

	taille = testEnv.taille();
	cout << "L'environnement \"testEnv\" a pour taille : (" << taille.x << ";" << taille.y << ")." << endl;
	
	taille.x = 5;
	taille.y = 5;
	Environnement testEnv2(taille);
	
	taille.x = 10;

	taille = testEnv2.taille();
	cout << "L'environnement \"testEnv2\" a pour taille : (" << taille.x << ";" << taille.y << ")." << endl;
	
	Almanach almanachForet;
	almanachForet[0] = "Vide";
	
	Entite testEntite;
	cout << "L'entite \"testEntite\" a pour nom : " << testEntite.obtenirNom(almanachForet) << "." << endl;
	
	CoupleEntiers position;
	position.x=0;
	position.y=0;
	testEnv2.insererEntite(position, testEntite);
	cout << "Insertion de l'entite \"testEntite\" dans l'environnement \"testEnv2\" a la position (0,0)." << endl;

	return 0;
}
