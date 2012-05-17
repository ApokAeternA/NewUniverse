/**
 * \file core.cpp
 * \author Nicolas Symphorien
 * \version 0.0.1
 * \date 16 mai 2012
 *
 * \brief Définitions de la partie core du progamme.
 *
 * Définitions des méthodes des classes de la partie core du programme.
 */

#include "core.h"

using namespace std;

/* Methode de la classe "Environnement" */

Environnement::Environnement() : m_map(1, vector<Entite>(1, Entite()))
{
}

Environnement::Environnement(CoupleEntiers taille) : m_map(taille.x, vector<Entite>(taille.y, Entite()))
{
}

Environnement::~Environnement()
{
}

CoupleEntiers Environnement::taille()
{
	CoupleEntiers tailleEnvironnement;

	tailleEnvironnement.x = m_map[0].size();
	tailleEnvironnement.y = m_map.size();

	return tailleEnvironnement;
}

void Environnement::insererEntite(CoupleEntiers pos, Entite entite)
{
	m_map[pos.x][pos.y] = entite;
}

/* Methodes de la classe "Entite" */

Entite::Entite() : m_ID(0)
{
}

Entite::~Entite()
{
}

Entite::Entite(Entite const& entiteCopier) : m_ID(entiteCopier.m_ID)
{
}


string Entite::obtenirNom(Almanach & envAlmanach)
{
	return envAlmanach[m_ID];
}

