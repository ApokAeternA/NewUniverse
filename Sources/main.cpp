#include <iostream>
#include <iostream>

#include "core.h"

using namespace std;

int main()
{
	cout << "Hello World" << endl;
	
	Environnement testEnv;
	size2D taille;

	taille = testEnv.size();
	cout << "L'environnement \"testEnv\" a pour taille : (" << taille.x << ";" << taille.y << ")." << endl;

	Environnement testEnv2(5, 5);

	taille = testEnv2.size();
	cout << "L'environnement \"testEnv2\" a pour taille : (" << taille.x << ";" << taille.y << ")." << endl;
	
	Almanach almanachForet;
	almanachForet[0] = "Vide";
	
	Entite testEntite;
	cout << "L'entite \"testEntite\" a pour nom : " << testEntite.obtenirNom(almanachForet) << "." << endl;

	return 0;
}
