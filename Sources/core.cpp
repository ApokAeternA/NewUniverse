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

/* Implémentation de la classe "Environnement" */

/* Constructeurs : */

Environnement::Environnement() : m_map(1, vector<Entite>(1, Entite()))
{
}

Environnement::Environnement(const unsigned int i, const unsigned int j) : m_map(i, vector<Entite>(j, Entite()))
{
}

Environnement::Environnement(const Environnement & envCopier) : m_map(envCopier.m_map)
{
}

/* Destructeur : */

Environnement::~Environnement()
{
}

/* Methodes : */

unsigned int Environnement::tailleEnX()
{
	return m_map[0].size();
}

unsigned int Environnement::tailleEnY()
{
	return m_map.size();
}

void Environnement::insererEntite(const unsigned int i, const unsigned j, Entite entite)
{
	m_map[i][j] = entite;
}

Entite Environnement::extraireEntite(const unsigned int i, const unsigned int j)
{
	return m_map[i][j];
}


/* Surcharges d'operateurs : */

Environnement& Environnement::operator=(const Environnement & envCopier)
{
	if(this != &envCopier)
	{
		m_map = envCopier.m_map;
	}

	return *this;
}

Entite& Environnement::operator()(const unsigned int i, const unsigned int j)
{
	return m_map[i][j];
}

/* Implemantation de la classe "Entite" */

/* Constructeurs : */

Entite::Entite() : m_ID(0)
{
}

Entite::Entite(unsigned int ID) : m_ID(ID)
{
}

Entite::Entite(const Entite & entiteCopier) : m_ID(entiteCopier.m_ID)
{
}

/* Destructeur : */

Entite::~Entite()
{
}

/* Methodes : */

string Entite::obtenirNom(Almanach & envAlmanach)
{
	return envAlmanach[m_ID];
}

/* Surchages d'operateurs : */

Entite& Entite::operator=(const Entite & entiteCopier)
{
	if(this != &entiteCopier)
	{
		m_ID = entiteCopier.m_ID;
	}

	return *this;
}
