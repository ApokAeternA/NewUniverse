#ifndef INCLUDE_CORE_H
#define INCLUDE_CORE_H

#include <vector>
#include <string>
#include <map>

struct size2D;
class Environnement;
class Entite;

typedef std::map<int, std::string> Almanach;

struct size2D
{
	int x, y;
};


class Environnement
{
	public :
		Environnement(); 
		Environnement(int x, int y);
		~Environnement();

		size2D size();
	
	private :
		std::vector<std::vector<Entite> > m_map;
};

class Entite
{
	public :
		Entite();
		~Entite();

		std::string obtenirNom(Almanach envAlmanach);
	
	private :
		int m_ID;
};

#endif
