/**
 * \file core.h
 * \author Nicolas Symphorien
 * \version 0.0.1
 * \date 16 mai 2012
 *
 * \brief En-tête de la partie core du programme.
 *
 * En-tête définisant les différentes classes et structures pour la partie core du programme.
 */

#ifndef INCLUDE_CORE_H
#define INCLUDE_CORE_H

#include <vector>
#include <string>
#include <map>

struct Size2D;
class Environnement;
class Entite;

/** 
 * \typedef std::map<int, std::string> Almanach
 * \brief Table d'association d'un entier et d'une chaîne.
 *
 * Cette table d'association permet de liée l'ID d'une entité à son nom.
 */
typedef std::map<int, std::string> Almanach;

/**
 * \struct CoupleEntiers
 * \brief Couple d'entiers.
 *
 * Cette structure permet de stockés deux entiers representant, par exemple, la taille d'un environnement en hauteur et largeur, ou bien, les coordonées de la position d'une entité dans un environnement.
 */
struct CoupleEntiers
{
	int x, y;
};

/**
 * \class Environnement
 *
 * \brief Classe représentant un environnement.
 *
 * Cette classe permet de stocker les données relative à un environemment donné.
 */
class Environnement
{
	public :
		/**
		 * \brief Constructeur par default de la classe Environnement.
		 *
		 * Ce constructeur créer un environnement de 1 sur 1 contenant l'entité "Vide" d'ID = 0.
		 */
		Environnement();
		/**
		 * \brief Constructeur de la classe Environnement.
		 *
		 * Ce constructeur créer un environnement de la taille spécifier en argument remplit avec l'entité "Vide" d'ID = 0.
		 * 
		 * \param taille : couple d'entiers spécifiant la taille de l'environnement à créer.
		 */
		Environnement(CoupleEntiers taille);
		/**
		 * \brief Destructeur de la classe Environnement.
		 */
		~Environnement();
		
		/**
		 * \brief Taille de l'environnement.
		 *
		 * Donne la taille de l'environnement
		 */
		CoupleEntiers taille();
		/**
		 * \brief Insertion d'une entite.
		 *
		 * Insert une entité dans l'environnement à la position donnés par le couple d'entiers pos.
		 *
		 * \param pos : couple d'entier donnant la position où inserer l'entité.
		 * \param entite : entité à inserer.
		 */
		void insererEntite(CoupleEntiers pos, Entite entite);
	
	private :
		std::vector<std::vector<Entite> > m_map; /**< Tableau de stokage des entités présente dans l'environnement */
};

/**
 * \class Entite
 *
 * \brief Classe représentant une entité.
 *
 * Cette classe sert à définir les différentes entités présentent dans un environnement donné.
 */
class Entite
{
	public :
		/**
		 * \brief Constructeur par default de la classe Entite.
		 *
		 * Ce constructeur créer une entité d'ID = 0.
		 */
		Entite();
		/**
		 * \brief Constructeur de copie de la classe Entite.
		 *
		 * Construit une copie de l'entité passé en argument.
		 *
		 * \param entiteCopier : entité à copier.
		 */
		Entite(Entite const& entiteCopier);
		/**
		 * \brief Destructeur de la classe Entite.
		 */
		~Entite();

		/**
		 * \brief Renvoi le nom associé à une entité.
		 *
		 * Recupére le nom de l'entité en ce servant de son ID et d'un Almanach.
		 *
		 * \param envAlmanach : almanach de l'environnement dans lequel ce trouve l'entité.
		 * \return le nom de l'entité.
		 */
		std::string obtenirNom(Almanach & envAlmanach);
	
	private :
		int m_ID; /**< ID de l'entité */
};

#endif
