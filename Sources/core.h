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
		 * \brief Constructeur par default.
		 *
		 * Ce constructeur créer un environnement de 1 sur 1 contenant l'entité "Vide" d'ID = 0.
		 */
		Environnement();
		/**
		 * \brief Constructeur.
		 *
		 * Ce constructeur créer un environnement de "i" sur "j"  remplit avec l'entité "Vide" d'ID = 0.
		 * 
		 * \param i : taille en largeur.
		 * \param j : taille en hauteur.
		 */
		Environnement(const unsigned int i, const unsigned int j);
		/**
		 * \brief Constructeur de copie.
		 *
		 * Ce constructeur créer une copie d'un environnement.
		 * 
		 * \param envCopier : environnement copier.
		 */
		Environnement(const Environnement & envCopier);
		/**
		 * \brief Destructeur.
		 */
		~Environnement();
		
		/**
		 * \brief Taille en X de l'environnement.
		 *
		 * Donne la taille en X de l'environnement.
		 *
		 * \return La taille de l'environnement en X.
		 */
		unsigned int tailleEnX();
		/**
		 * \brief Taille en Y de l'environnement.
		 *
		 * Donne la taille en Y de l'environnement.
		 *
		 * \return La taille de l'environnement en Y.
		 */
		unsigned int tailleEnY();
		/**
		 * \brief Insertion d'une entité.
		 *
		 * Insert une entité dans l'environnement à la position (i, j).
		 *
		 * \param i : entier donnant la position en X où inserer l'entité.
		 * \param j : entier donnant la position en Y où inserer l'entité.
		 * \param entite : entité à inserer.
		 */
		void insererEntite(const unsigned int i, const unsigned j, Entite entite);
		/**
		 * \brief Extraction d'une entité.
		 *
		 * Extrait une entité de l'environnement situé à la position (i, j).
		 *
		 * \param i : entier donnant la position en X où extraire l'entité.
		 * \param j : entier donnant la position en Y où extraire l'entité.
		 * \return L'entité situé en (i, j)
		 */
		Entite extraireEntite(const unsigned int i, const unsigned int j);

		/**
		 * \brief Opérateur d'affectation.
		 *
		 * Cette surchage permet d'utiliser la classe Environnement avec l'operateur d'affectation.
		 * 
		 * \param envCopier : environnement affecter.
		 * \return la copie de l'entité donner en entrée
		 */
		Environnement& operator=(const Environnement & envCopier);
		/**
		 * \brief Opérateur fonctionnel.
		 *
		 * Cette surchage permet d'utiliser la classe Environnement comme un tableau à 2 entrées, en se servant de l'ecriture "environnement(i,j)" pour atteindre une entité situé en (i, j).
		 * 
		 * \param i : position sur l'axe X de l'entité à atteindre.
		 * \param j : position sur l'axe Y de l'entité à atteindre.
		 * \return Une reference sur l'entité situé en (i, j).
		 */
		Entite& operator()(const unsigned int i, const unsigned int j);
	
	private :
		std::vector<std::vector<Entite> > m_map; // Tableau de stokage des entités présente dans l'environnement
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
		 * \brief Constructeur.
		 *
		 * Construit une entité avec l'ID spécifier en argument.
		 *
		 * \param ID : ID de l'entité crée.
		 */
		Entite(unsigned int ID);
		/**
		 * \brief Constructeur de copie de la classe Entite.
		 *
		 * Construit une copie de l'entité passé en argument.
		 *
		 * \param entiteCopier : entité à copier.
		 */
		Entite(const Entite & entiteCopier);
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
		
		Entite& operator=(const Entite & entiteCopier); 
	private :
		unsigned int m_ID;
};

#endif
