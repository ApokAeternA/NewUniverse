#include "core.h"

using namespace std;

Environnement::Environnement() : m_map(1, vector<Entite>(1, Entite()))
{
}

Environnement::Environnement(int x, int y) : m_map(x, vector<Entite>(y, Entite()))
{
}

Environnement::~Environnement()
{
}

size2D Environnement::size()
{
	size2D tailleEnvironnement;

	tailleEnvironnement.x = m_map[0].size();
	tailleEnvironnement.y = m_map.size();

	return tailleEnvironnement;
}

Entite::Entite() : m_ID(0)
{
}

Entite::~Entite()
{
}

string Entite::obtenirNom(Almanach envAlmanach)
{
	return envAlmanach[m_ID];
}
